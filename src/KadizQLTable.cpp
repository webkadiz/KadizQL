#include <string>
#include <iostream>
#include <fstream>
#include <fstream>
#include <vector>
#include "../include/KadizQLDB.h"
#include "../include/KadizQLTable.h"
#include "../include/utils.h"
#include "../include/KadizQLFieldScheme.h"
#include "../include/CSVParser.h"

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
}

void Table::createScheme(vector<vector<string>> tableSchemeData) {
    fs::path tableDir = this->getTableDir();
    fs::path tableSchemeFilePath = tableDir / tableName;
    string tableSchemeFileName = tableSchemeFilePath.string() + ".scheme";

    ofstream tableSchemeFile (tableSchemeFileName);

    for (vector<string> params: tableSchemeData) {
        FieldScheme *fieldScheme = new FieldScheme(params);

        bool isAllParamsProcessed = fieldScheme->processParams();

        if (isAllParamsProcessed == false) {
            throw std::exception();
        }

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

        this->tableScheme->addFieldScheme(fieldScheme);
    }

    tableSchemeFile.close();
}

Field *Table::select(vector<string> fieldNames) {
    string tableDataFileName = this->getTableDir() / (tableName + ".data");
    int countLines, countErrors;
    string line;
    string textForParsing;
    vector<string> parsedRowFields;
    CSVParser *csvParser = new CSVParser();
    ifstream tableDataFile (tableDataFileName);


    while(true) {
        line = readLine(tableDataFile);
        countLines++;

        if (line.empty()) break;

        textForParsing += line;
        try {
            parsedRowFields = csvParser->parse(textForParsing)[0];
        } catch(std::exception &e) {
            countErrors++;
        }
    }

    if (countErrors == countLines) {

    }

}