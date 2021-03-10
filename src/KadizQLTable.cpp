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
    return DB::getDBDir() / tableName;
}

bool Table::create(vector<vector<string>> tableSchemeData) {

    if (DB::getUsedDB().empty()) {
        cerr << "you should choose database before create table";
        return false;
    }

    if (fs::exists(getTableDir())) return true;

    try {
        fs::create_directory(getTableDir());
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
    loadScheme();
    fs::path tableDir = this->getTableDir();
    fs::path tableStorageFilePath = tableDir / tableName;
    string tableStorageFileNameBase = tableStorageFilePath.string();
    string tableStorageFileName;

    cout << tableScheme.length() << endl;

    for (size_t i = 0; i < tableScheme.length(); i++) {
        FieldScheme *fieldScheme = tableScheme[i];

        tableStorageFileName = tableStorageFileNameBase + "." + fieldScheme->getName();

        cout << tableStorageFileName << endl;
        ofstream tableStorageFile (tableStorageFileName);        
    }
}

void Table::loadScheme() {
    string tableSchemeFileName = this->getTableDir() / (tableName + ".scheme");

    ifstream tableSchemeFile (tableSchemeFileName);

    string tableSchemeText = readFile(tableSchemeFile);

    CSVParser *csvParser = new CSVParser();

    vector<vector<string>> tableSchemeData = csvParser->parse(tableSchemeText);

    tableScheme = TableScheme(tableSchemeData);

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

Result Table::insert(Row &row) {
    Result result;
    string dataFileNameBase = this->getTableDir() / tableName;

    ios_base::openmode mode = ofstream::out | ofstream::app | ofstream::binary;
    vector<ofstream> dataFiles(row.length());

    for (size_t i = 0; i < row.length(); i++) {
        Field *field = row.at(i);
        string fieldName = field->getName();
        string dataFileName = dataFileNameBase + "." + fieldName;

        cout << dataFileName << endl;

        dataFiles.at(i).open(dataFileName, mode);
        
        dataFiles.at(i).write(field->getEncodedData(), field->getEncodedSize());

        dataFiles.at(i).close();
    }

    return result;
}
