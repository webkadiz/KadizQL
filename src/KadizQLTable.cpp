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
    tableShemeLoaded = false;
}

fs::path Table::getTableDir() {
    return DB::getDBDir() / tableName;
}

string Table::getTableDataBasename() {
    return (getTableDir() / tableName).string() + ".";
}

bool Table::create(vector<vector<string>> tableSchemeData) {

    if (DB::getUsedDB().empty()) {
        cerr << "you should choose database before create table";
        return false;
    }

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
    string tableSchemeFileName = getTableDataBasename() + "scheme";

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

    for (size_t i = 0; i < tableScheme.length(); i++) {
        FieldScheme *fieldScheme = tableScheme[i];

        tableStorageFileName = tableStorageFileNameBase + "." + fieldScheme->getName();

        ofstream tableStorageFile (tableStorageFileName);        
    }
}

void Table::loadScheme() {
    if (tableShemeLoaded) return;

    string tableSchemeFileName = this->getTableDir() / (tableName + ".scheme");

    ifstream tableSchemeFile (tableSchemeFileName);

    string tableSchemeText = readFile(tableSchemeFile);

    CSVParser *csvParser = new CSVParser();

    vector<vector<string>> tableSchemeData = csvParser->parse(tableSchemeText);

    tableScheme = TableScheme(tableSchemeData);

    tableSchemeFile.close();

    tableShemeLoaded = true;
}

void Table::clearData() {
    for (size_t i = 0; i < tableScheme.length(); i++) {
        FieldScheme *fieldScheme = tableScheme[i];

        string fieldName = fieldScheme->getName();
        string dataFileName = getTableDataBasename() + fieldName;

        ofstream dataFile(dataFileName);

        dataFile.close();
    }
}

size_t Table::getRowsCount() {
    if (tableScheme.length() == 0) return 0;

    FieldScheme *fieldScheme = tableScheme[0];
    string dataFileName = getTableDataBasename() + fieldScheme->getName();

    ifstream dataFile(dataFileName);

    dataFile.seekg(0, dataFile.end);
    size_t dataFileLength = dataFile.tellg();
    dataFile.seekg(0, dataFile.beg);

    dataFile.close();

    size_t rowsCount = dataFileLength / fieldScheme->getEncodedSize();

    return rowsCount;
}

Row Table::readRow(size_t rowIdx) {
    Row row;

    for (size_t i = 0; i < tableScheme.length(); i++) {
        FieldScheme *fieldScheme = tableScheme[i];

        string fieldName = fieldScheme->getName();
        string dataFileName = getTableDataBasename() + fieldName;

        ifstream dataFile(dataFileName);

        char *fieldValue = new char[fieldScheme->getEncodedSize()];

        dataFile.seekg(rowIdx * fieldScheme->getEncodedSize());
        dataFile.read(fieldValue, fieldScheme->getEncodedSize());
        dataFile.close();

        Field *field = FieldFabric::createField(fieldValue, fieldScheme->getType());

        row.add(field, fieldScheme->getName());

        delete[] fieldValue;
    }

    return row;
}

Row Table::selectFromRow(Row &row, vector<string> &fieldNames) {
    Row rowSelection;

    for (size_t i = 0; i < fieldNames.size(); i++) {
        string fieldName = fieldNames[i];

        rowSelection.add(row[fieldName], fieldName);
    }

    return rowSelection;
}

Result Table::select(vector<string> fieldNames, Condition *cond) {
    loadScheme();

    Result res;
    size_t rowsCount = getRowsCount();

    for (size_t i = 0; i < rowsCount; i++) {
        Row row, rowSelection;

        row = readRow(i);

        if (cond->exec(row)) {
            rowSelection = selectFromRow(row, fieldNames);

            res.incAffectedRowsCount();

            res.add(rowSelection);
        }
    }

    return res;
}

Result Table::insert(Row &row) {
    loadScheme();

    Result res;

    if (tableScheme.length() != row.length()) {
        return res;
    }

    ios_base::openmode mode = ofstream::out | ofstream::app | ofstream::binary;
    vector<ofstream> dataFiles(row.length());

    for (size_t i = 0; i < row.length(); i++) {
        Field *field = row.at(i);
        string fieldName = tableScheme[i]->getName();
        string fieldType = tableScheme[i]->getType();
        string dataFileName = this->getTableDataBasename() + fieldName;

        dataFiles.at(i).open(dataFileName, mode);
        
        dataFiles.at(i).write(field->getEncodedData(), field->getEncodedSize());

        dataFiles.at(i).close();
    }

    res.incAffectedRowsCount();

    return res;
}

Result Table::update(string fieldName, Field *field, Condition *cond) {
    loadScheme();

    Result res;

    ios_base::openmode mode = fstream::in | fstream::out | fstream::binary;
    fstream dataFile;

    fieldName = toUpperCase(fieldName);
    string dataFileName = getTableDataBasename() + fieldName;

    dataFile.open(dataFileName, mode);

    size_t rowsCount = getRowsCount();

    for (size_t i = 0; i < rowsCount; i++) {
        Row row;

        row = readRow(i);

        if (cond->exec(row)) {
            dataFile.seekg(i * field->getEncodedSize());
            dataFile.write(field->getEncodedData(), field->getEncodedSize());

            res.incAffectedRowsCount();
        }
    }

    dataFile.close();

    return res;
}

Result Table::remove(Condition *cond) {
    loadScheme();

    Result res;
    vector<Row> restRows;
    size_t rowsCount = getRowsCount();

    for (size_t i = 0; i < rowsCount; i++) {
        Row row;

        row = readRow(i);

        if (cond->exec(row)) {
            res.incAffectedRowsCount();
            continue;
        }

        restRows.push_back(row);
    }

    clearData();

    for (size_t i = 0; i < restRows.size(); i++) {
        insert(restRows[i]);
    }

    return res;
}
