#include <string>
#include <variant>
#include "../include/KadizQLFieldVarchar.h"

using namespace std;
using namespace KadizQL;

FieldVarchar::FieldVarchar(string fieldValue, FieldScheme *fieldScheme) :
    Field(fieldScheme) {
    
    for (size_t i = 0; i < fieldValue.length(); i++) {
        binaryFieldValue[i] = fieldValue[i];    
    }

    for (size_t i = 0; i < sizeof(binaryFieldValue) - fieldValue.length(); i++) {
        binaryFieldValue[i] = 0;    
    }

    stringFieldValue = fieldValue;
}

dataTypes FieldVarchar::data() {
    return (dataTypes) stringFieldValue;
}

char *FieldVarchar::getEncodedData() {
    return binaryFieldValue;
}

size_t FieldVarchar::getEncodedSize() {
    return sizeof(binaryFieldValue);
}