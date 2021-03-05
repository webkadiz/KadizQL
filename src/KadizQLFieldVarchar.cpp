#include <string>
#include <variant>
#include "../include/KadizQLFieldVarchar.h"

using namespace std;
using namespace KadizQL;

FieldVarchar::FieldVarchar(string fieldValue, FieldScheme *fieldScheme) :
    Field(fieldValue, fieldScheme) {
    processedValue();
}

void FieldVarchar::processedValue() {
    realFieldValue = fieldValue;
}

dataTypes FieldVarchar::data() {
    return (dataTypes) realFieldValue;
}
