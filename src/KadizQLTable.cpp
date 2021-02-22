#include <string>
#include <iostream>
#include <fstream>
#include <fstream>
#include <vector>
#include "../include/KadizQLDB.h"
#include "../include/KadizQLTable.h"

using namespace std;
using namespace KadizQL;
namespace fs = std::filesystem;


Table::Table(string tableName) {
    this->tableName = tableName;
}

fs::path Table::getTableDir() {
    return DB::getDBDir() / this->tableName;
}

bool Table::create(vector<vector<string>> fields) {

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

    this->createScheme(fields);
    this->createStorage();
}

bool Table::createScheme(vector<vector<string>> fields) {
    fs::path tableDir = this->getTableDir();
    fs::path tableSchemeFilePath = tableDir / tableName;
    string tableSchemeFileName = tableSchemeFilePath.string() + ".scheme";

    ofstream tableSchemeFile (tableSchemeFileName);

    for (vector<string> field: fields) {
        for(string fieldParam: field) {
            tableSchemeFile << fieldParam + " ";
        }
        tableSchemeFile << "\n";
    }

    tableSchemeFile.close();

    return true;
}

bool Table::createStorage() {
    fs::path tableDir = this->getTableDir();
    fs::path tableStorageFilePath = tableDir / tableName;
    string tableStorageFileName = tableStorageFilePath.string() + ".data";

    ofstream tableStorageFile (tableStorageFileName);

    tableStorageFile.close();

    return true;
}

string Table::readTableFromFile(string filename) {
    string fileContent, line;
    ifstream file;
    
    file.open(filename);

    if (file.is_open()) {
        while(getline(file, line)) fileContent += line + "\n";
        file.close();
        return fileContent;
    } else {
        cout << "Error: file " + filename + " not open";
        fileContent = "";
        return fileContent;
    }
}

void Table::readTable() {

}

void Table::writeTable() {

}
