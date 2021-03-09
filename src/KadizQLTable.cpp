#include <iostream>
#include <fstream>
#include <fstream>
#include "../include/KadizQLDB.h"
#include "../include/KadizQLTable.h"
#include "../include/utils.h"
#include "../include/KadizQLFieldScheme.h"
#include "../include/CSVParser.h"
#include "../include/KadizQLRow.h"
#include "../include/KadizQLFieldFabric.h"

using namespace std;
using namespace KadizQL;
namespace fs = std::filesystem;


Table::Table(string tableName) {
    this->tableName = tableName;
}

fs::path Table::getTableDir() {
    return DB::getDBDir() / this->tableName;
}

bool Table::create(vector<vector<string>> tableSchemeData) {

    if (DB::getUsedDB().empty()) {
        cerr << "you should choose database before create table";
        return false;
    }

    try {
        fs::create_directory(this->getTableDir());
    } catch(fs::filesystem_error& e) {
        cerr << "directory " << tableName << " cann't be created";
        return false;
    }


    try {
        this->createScheme(tableSchemeData);
    } catch(std::exception &e) {
        cerr << "can not create scheme";
    }
    this->createStorage();

    return true;
}

void Table::createScheme(vector<vector<string>> tableSchemeData) {
    fs::path tableDir = this->getTableDir();
    fs::path tableSchemeFilePath = tableDir / tableName;
    string tableSchemeFileName = tableSchemeFilePath.string() + ".scheme";

    ofstream tableSchemeFile (tableSchemeFileName);

    for (vector<string> params: tableSchemeData) {
        FieldScheme *fieldScheme = new FieldScheme(params);

        vector<string> processedParams = fieldScheme->getProcessedParams();

        for (string param: processedParams) {
            tableSchemeFile << param;
            if (param == processedParams.back()) continue;
            tableSchemeFile << ",";
        }
        tableSchemeFile << "\n";
    }

    tableSchemeFile.close();
}

void Table::createStorage() {
    fs::path tableDir = this->getTableDir();
    fs::path tableStorageFilePath = tableDir / tableName;
    string tableStorageFileName = tableStorageFilePath.string() + ".data";

    if (fs::exists(tableStorageFileName)) return;

    ofstream tableStorageFile (tableStorageFileName);

    tableStorageFile.close();
}

void Table::loadScheme() {
    string tableSchemeFileName = this->getTableDir() / (tableName + ".scheme");

    ifstream tableSchemeFile (tableSchemeFileName);

    string tableSchemeText = readFile(tableSchemeFile);

    CSVParser *csvParser = new CSVParser();

    vector<vector<string>> tableSchemeData = csvParser->parse(tableSchemeText);

    for(vector<string> params: tableSchemeData) {
        FieldScheme *fieldScheme = new FieldScheme(params);

        this->tableScheme.addFieldScheme(fieldScheme);
    }

    tableSchemeFile.close();
}

Result Table::select(vector<string> fieldNames) {
    string tableDataFileName = this->getTableDir() / (tableName + ".data");
    int countLines, countErrors;
    string line;
    string textForParsing;
    vector<string> parsedRowFields;
    CSVParser *csvParser = new CSVParser();
    ifstream tableDataFile (tableDataFileName);
    vector<int> fieldOffset;
    Result result;

    for (string fieldName: fieldNames) {
        int offset = this->tableScheme.getFieldOffsetByName(fieldName); 
        fieldOffset.push_back(offset);
    }

    while(true) {
        Row row;
        line = readLine(tableDataFile);
        countLines++;

        if (line.empty()) break;

        textForParsing += line;
        try {
            parsedRowFields = csvParser->parse(textForParsing).at(0);

            for (size_t i = 0; i < fieldNames.size(); i++) {
                string fieldName = fieldNames[i];
                int offset = fieldOffset[i]; 
                string fieldValue = parsedRowFields[offset];
                
                FieldScheme *fieldScheme = this->tableScheme[offset];

                Field *field = FieldFabric::createField(fieldValue, fieldScheme);

                row.addField(field);
            }

            result.addRow(row);
            textForParsing = "";          
        } catch(std::exception &e) {
            countErrors++;
        }
    }

    if (countErrors == countLines) {

    }

    return result;
}

Result Table::insert(vector<vector<string>> tableData) {
    Result result;
    string tableDataFileName = this->getTableDir() / (tableName + ".data");

    ofstream tableDataFile;
    tableDataFile.open(tableDataFileName, ofstream::out | ofstream::app);

    for (vector<string> row: tableData) {
        for (string field: row) {
            tableDataFile << field;
            if (field == row.back()) continue;
            tableDataFile << ",";
        }
        tableDataFile << "\n";
    }

    return result;
}
