#include <string>
#include "../include/KadizQLFieldInt.h"

using namespace std;
using namespace KadizQL;

FieldInt::FieldInt(string fieldValue, FieldScheme &fieldScheme) :
    Field(fieldValue, fieldScheme) {
    this->processedValue();
}

int FieldInt::processedValue() {
    this->realFieldValue = stoi(this->fieldValue);
}

int FieldInt::data() {
    return realFieldValue;
}

FieldInt::operator int() {
    return realFieldValue;
}
