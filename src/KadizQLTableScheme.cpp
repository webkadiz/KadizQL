#include "../include/KadizQLTableScheme.h"

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

    return offset
}