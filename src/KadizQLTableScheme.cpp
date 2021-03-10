#include <vector>
#include <string>
#include <stdexcept>
#include "../include/KadizQLTableScheme.h"
#include "../include/KadizQLFieldScheme.h"
#include "../include/utils.h"

using namespace std;
using namespace KadizQL;

TableScheme::TableScheme() {}

TableScheme::TableScheme(vector<vector<string>> schemes) {
    for (vector<string> fieldSchemeVector: schemes) {
        FieldScheme *fieldScheme = new FieldScheme(fieldSchemeVector);

        fieldSchemes.push_back(fieldScheme);
    }
}

int TableScheme::getFieldOffsetByName(string fieldName) {

    int idx = 0, offset = -1;
    for (FieldScheme *fieldScheme: fieldSchemes) {
        fieldName = toUpperCase(fieldName);
        if (fieldScheme->getName() == fieldName) {
            offset = idx;
            break;
        }
        idx++;
    }

    return offset;}

FieldScheme *TableScheme::operator[](size_t idx) {
    return at(idx);
}

FieldScheme *TableScheme::at(size_t idx) {
    return fieldSchemes.at(idx);
}

void TableScheme::at(size_t idx, FieldScheme *fieldScheme) {
    if (idx < fieldSchemes.size()) {
        fieldSchemes[idx] = fieldScheme;
    }
}

size_t TableScheme::length() {
    return fieldSchemes.size();
}