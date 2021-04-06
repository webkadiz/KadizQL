#include <string>
#include <variant>
#include "../include/KadizQLFieldText.h"

using namespace std;
using namespace KadizQL;

FieldText::FieldText(string fieldValue) {
    
    for (size_t i = 0; i < fieldValue.length(); i++) {
        binaryFieldValue[i] = fieldValue[i];    
    }

    for (size_t i = 0; i < sizeof(binaryFieldValue) - fieldValue.length(); i++) {
        binaryFieldValue[i] = 0;    
    }

    stringFieldValue = fieldValue;
}

dataTypes FieldText::data() {
    return (dataTypes) stringFieldValue;
}

char *FieldText::getEncodedData() {
    return binaryFieldValue;
}

size_t FieldText::getEncodedSize() {
    return sizeof(binaryFieldValue);
}
