#include <string>
#include <variant>
#include <iostream>
#include "../include/KadizQLFieldText.h"

using namespace std;
using namespace KadizQL;

FieldText::FieldText(string fieldValue) {
    binaryFieldValue = string(255, 0);

    for (size_t i = 0; i < fieldValue.size(); i++) {
        binaryFieldValue[i] = fieldValue[i];  
    }
}

dataTypes FieldText::data() {
    return (dataTypes) binaryFieldValue;
}

string FieldText::getType() {
    return "TEXT";
}

char *FieldText::getEncodedData() {
    return binaryFieldValue.data();
}

size_t FieldText::getEncodedSize() {
    return binaryFieldValue.size();
}
