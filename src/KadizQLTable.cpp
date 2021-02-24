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

bool Table::create(vector<vector<string>> tableDesc) {

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
        this->createScheme(tableDesc);
    } catch(std::exception &e) {
        cerr << "can not create scheme";
    }
    this->createStorage();
}

void Table::createScheme(vector<vector<string>> tableDesc) {
    fs::path tableDir = this->getTableDir();
    fs::path tableSchemeFilePath = tableDir / tableName;
    string tableSchemeFileName = tableSchemeFilePath.string() + ".scheme";

    ofstream tableSchemeFile (tableSchemeFileName);

    for (vector<string> params: tableDesc) {
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

void Table::load() {
    string tableSchemeFileName = this->getTableDir() / (tableName + ".scheme");

    ifstream tableSchemeFile (tableSchemeFileName);

    string schemeText = readFile(tableSchemeFile);

    CSVParser *csvParser = new CSVParser();

    csvParser->prepare();
    vector<vector<string>> scheme = csvParser->parse(schemeText);

    for(vector<string> column: scheme) {
        for (string field: column) {
            cout << field;
        }
    }

    tableSchemeFile.close();
}