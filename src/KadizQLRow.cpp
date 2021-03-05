#include <vector>
#include <stdexcept>
#include "../include/KadizQLField.h"
#include "../include/KadizQLRow.h"

using namespace std;
using namespace KadizQL;

Row::Row() {}

Row::Row(vector<Field *> row) {
    this->row = row;
}

Field *Row::operator[](string key) {
    try {
        return this->fieldMap.at(key);
    } catch(std::out_of_range &e) {
        return (Field *) 0;
    }
}


void Row::addField(Field *field) {
    this->row.push_back(field);
    string fieldName = field->getName();

    this->fieldMap[fieldName] = field;
}