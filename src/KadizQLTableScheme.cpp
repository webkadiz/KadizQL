#include "../include/KadizQLTableScheme.h"
#include <stdexcept>

using namespace std;
using namespace KadizQL;

void TableScheme::addFieldScheme(FieldScheme *fieldScheme) noexcept {
    this->fieldSchemes.push_back(fieldScheme);
}

int TableScheme::getFieldOffsetByName(string fieldName) {

    int idx = 0, offset = -1;
    for (FieldScheme *fieldScheme: fieldSchemes) {
        if (fieldScheme->getName() == fieldName) {
            offset = idx;
            break;
        }
        idx++;
    }

    return offset;
}

FieldScheme *TableScheme::operator[](int idx) {
    try {
        FieldScheme *fieldScheme = this->fieldSchemes.at(idx);

        return fieldScheme;
    } catch(std::out_of_range &e) {
        return (FieldScheme *) 0;
    }
}