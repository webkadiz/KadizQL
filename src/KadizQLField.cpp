#include <string>
#include <variant>
#include "../include/KadizQLField.h"

using namespace std;
using namespace KadizQL;

Field::Field(string fieldValue, FieldScheme *fieldScheme) {
    this->fieldValue = fieldValue;
    this->fieldScheme = fieldScheme;
}

Field::~Field() {}

string Field::getName() {
    return this->fieldScheme->getName();
}

dataTypes Field::data() {
    dataTypes v = 1;
    return v;
}
