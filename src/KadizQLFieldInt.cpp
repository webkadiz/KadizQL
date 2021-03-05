#include <string>
#include <variant>
#include "../include/KadizQLFieldInt.h"

using namespace std;
using namespace KadizQL;

FieldInt::FieldInt(string fieldValue, FieldScheme *fieldScheme) :
    Field(fieldValue, fieldScheme) {
    processedValue();
}

void FieldInt::processedValue() {
    realFieldValue = stoi(fieldValue);
}

dataTypes FieldInt::data() {
    return (dataTypes) realFieldValue;
}
