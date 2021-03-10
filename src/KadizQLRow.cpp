#include <vector>
#include <stdexcept>
#include <iostream>
#include "../include/KadizQLField.h"
#include "../include/KadizQLRow.h"
#include "../include/utils.h"

using namespace std;
using namespace KadizQL;

Row::Row() {}

Row::Row(vector<Field *> fields, TableScheme tableScheme_) {
    tableScheme = tableScheme_;

    for (size_t i = 0; i < tableScheme.length(); i++) {
        Field *field = fields.at(i);

        fieldVector.push_back(field);
    }
}

Field *Row::operator[](string key) {
    try {
        key = toUpperCase(key);
        return this->fieldMap.at(key);
    } catch(out_of_range &e) {
        return nullptr;
    }
}

Field *Row::operator[](size_t key) {
    try {
        return this->fieldVector.at(key);
    } catch(out_of_range &e) {
        return nullptr;
    }
}

Field *Row::at(size_t idx) {
    return this->fieldVector.at(idx);
}


Field *Row::at(string key) {
    return this->fieldMap.at(key);
}

void Row::at(size_t idx, Field *field) {
    if (idx < fieldVector.size()) {
        fieldVector[idx] = field;
    } else {
        clog << "Row: idx larger vector size";
    }
}

void Row::at(string key, Field *field) {
    key = toUpperCase(key);

    for (size_t i = 0; i < tableScheme.length(); i++) {
        if (key == tableScheme[i]->getName()) {
            fieldMap[key] = field;
            return;
        }
    }

    clog << "Row: key not contains in table scheme";
}

size_t Row::length() {
    return fieldVector.size();
}

void Row::addField(Field *field) {
    string fieldName = field->getName();

    if (this->fieldMap[fieldName]) throw exception();

    this->fieldVector.push_back(field);
    this->fieldMap[fieldName] = field;
}