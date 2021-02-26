#include "../include/KadizQLField.h"
#include <iostream>

using namespace KadizQL;

Field::Field(string fieldValue, FieldScheme &fieldScheme) {
    this->fieldValue = fieldValue;
    this->fieldScheme = fieldScheme;
}

Field::~Field() {}

string Field::getName() {
    return this->fieldScheme.getName();
}
