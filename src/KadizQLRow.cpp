#include <vector>
#include <stdexcept>
#include <iostream>
#include "../include/KadizQLField.h"
#include "../include/KadizQLRow.h"
#include "../include/utils.h"

using namespace std;
using namespace KadizQL;

Field *Row::operator[](string key) {
    return at(key);
}

Field *Row::operator[](size_t idx) {
    return at(idx);
}

Field *Row::at(string key) {
    try {
        key = toUpperCase(key);
        return fieldMap.at(key);
    } catch(out_of_range &e) {
        return nullptr;
    }
}

Field *Row::at(size_t idx) {
    try {
        return fieldVector.at(idx);
    } catch(out_of_range &e) {
        return nullptr;
    }
}

void Row::at(size_t idx, Field *field) {
    fieldVector.at(idx);
    fieldVector[idx] = field;
    fieldMap[fieldNamesVector[idx]] = field;
}

void Row::at(string key, Field *field) {
    key = toUpperCase(key);
    fieldMap.at(key);
    fieldMap[key] = field;
    fieldVector[fieldNamesMap[key]] = field;
}

size_t Row::length() {
    return fieldVector.size();
}

void Row::add(Field *field, string key) {
    size_t idx = fieldVector.size();
    key = toUpperCase(key);
    
    if (fieldMap.find(key) != fieldMap.end()) throw exception();

    fieldVector.push_back(field);
    fieldNamesVector.push_back(key);
    fieldNamesMap[key] = idx;
    fieldMap[key] = field;
}
