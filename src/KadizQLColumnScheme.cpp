#include <iostream>
#include "../include/KadizQLColumnScheme.h"
#include "../include/utils.h"

using namespace std;
using namespace KadizQL;

const vector<string> ColumnScheme::TYPES = {"INT", "FLOAT", "VARCHAR", "TEXT", "DATE"};

ColumnScheme::ColumnScheme(vector<string> fields) {
    this->fields = fields;
}

vector<string> ColumnScheme::getFields() {
    return this->fields;
}

bool ColumnScheme::processFields() {
    int fieldIdx = 0;

    try {
        this->processName(fieldIdx);
        this->processType(fieldIdx);
        this->processNotNull(fieldIdx);
        this->processDefault(fieldIdx);
        this->processAutoIncrement(fieldIdx);
        this->processPrimaryKey(fieldIdx);

        return true;
    } catch(std::out_of_range &e) {
        return false;
    } catch(std::exception &e) {
        return false;
    }
}

void ColumnScheme::processName(int &idx) {
    try {
        string field = this->fields.at(idx);

        this->fields[idx] = field = toUpperCase(field);
        this->name = field;
        idx++;
    } catch(std::out_of_range &e) {
        cerr << "set name for column";

        throw e;
    }
}

void ColumnScheme::processType(int &idx) {
    try {
        string field = this->fields.at(idx);

        this->fields[idx] = field = toUpperCase(field);

        for (string type: TYPES) {
            if (field.find(type) == 0) {
                this->type = type;
                break;
            }
        }

        if (this->type.empty()) {
            throw std::exception();
        }

        idx++;
    } catch(std::out_of_range &e) {
        cerr << "set type for column";

        throw e;
    } catch(std::exception &e) {
        cerr << "such type doesn't exists";

        throw e;
    }
}

void ColumnScheme::processNotNull(int &idx) {
    try {
        string field = this->fields.at(idx);

        this->fields[idx] = field = toUpperCase(field);

        if (field == "NOT NULL") {
            this->isNotNull = true;
            idx++;
        }
    } catch(std::out_of_range &e) {}
}

void ColumnScheme::processDefault(int &idx) {
    try {
        string field = this->fields.at(idx);

        this->fields[idx] = field = toUpperCase(field);

        if (field.find("DEFAULT") == 0) {
            this->isDefault = true;
            idx++;
        }
    } catch(std::out_of_range &e) {}
}

void ColumnScheme::processAutoIncrement(int &idx) {
    try {
        string field = this->fields.at(idx);

        this->fields[idx] = field = toUpperCase(field);

        if (field.find("AUTO INCREMENT") == 0) {
            this->isAutoIncrement = true;
            idx++;
        }
    } catch(std::out_of_range &e) {}
}

void ColumnScheme::processPrimaryKey(int &idx) {
    try {
        string field = this->fields.at(idx);

        this->fields[idx] = field = toUpperCase(field);

        if (field.find("PRIMARY KEY") == 0) {
            this->isPrimaryKey = true;
            idx++;
        }
    } catch(std::out_of_range &e) {}
}