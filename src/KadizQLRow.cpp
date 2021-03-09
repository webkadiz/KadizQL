#include <vector>
#include <stdexcept>
#include "../include/KadizQLField.h"
#include "../include/KadizQLRow.h"
#include "../include/utils.h"

using namespace std;
using namespace KadizQL;

Row::Row() {}

Row::Row(vector<Field *> row) {
    this->row = row;
}

Field *Row::operator[](string key) {
    try {
        key = toUpperCase(key);
        return this->fieldMap.at(key);
    } catch(out_of_range &e) {
        return nullptr;
    }
}

void Row::addField(Field *field) {
    string fieldName = field->getName();

    if (this->fieldMap[fieldName]) throw exception();

    this->row.push_back(field);
    this->fieldMap[fieldName] = field;
}