#include <string>
#include <variant>
#include "../include/KadizQLField.h"

using namespace std;
using namespace KadizQL;

Field::Field(FieldScheme *fieldScheme) {
    this->fieldScheme = fieldScheme;
}

Field::~Field() {}

string Field::getName() {
    return this->fieldScheme->getName();
}
