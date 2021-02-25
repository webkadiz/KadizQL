#include "../include/KadizQLField.h"

using namespace KadizQL;

Field::Field(string fieldValue, FieldScheme &fieldScheme) {
    this->fieldValue = fieldValue;
    this->fieldScheme = fieldScheme;
}

string Field::getName() {
    return this->fieldScheme.getName();
}