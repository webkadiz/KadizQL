#include <string>
#include "../include/KadizQLFieldInt.h"

using namespace std;
using namespace KadizQL;

FieldInt::FieldInt(string fieldValue, FieldScheme fieldScheme) :
    Field(fieldValue, fieldScheme) {}

void FieldInt::processedValue() {
    this->realFieldValue = stoi(this->fieldValue);
}

int FieldInt::getValue() {
    this->processedValue();
    return realFieldValue;
}
