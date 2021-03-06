#include <string>
#include <variant>
#include <iostream>
#include "../include/KadizQLFieldInt.h"

using namespace std;
using namespace KadizQL;

FieldInt::FieldInt(string fieldValue) {
    binaryFieldValue = string(4, 0);

    for (size_t i = 0; i < fieldValue.size(); i++) {
        binaryFieldValue[i] = fieldValue[i];    
    }

    decode();
}

FieldInt::FieldInt(int fieldValue) {
    binaryFieldValue = string(4, 0);
    intFieldValue = fieldValue;
    encode();
}

void FieldInt::decode() {
    for (int i = 0; i < 4; i++) {
        (reinterpret_cast<char *>(&intFieldValue))[i] = binaryFieldValue[i];
    }
}

void FieldInt::encode() {
    for (int i = 0; i < 4; i++) {
        binaryFieldValue[i] = reinterpret_cast<char *>(&intFieldValue)[i];
    }
}

dataTypes FieldInt::data() {
    return (dataTypes) intFieldValue;
}

string FieldInt::getType() {
    return "INT";
}

char *FieldInt::getEncodedData() {
    return binaryFieldValue.data();
}

size_t FieldInt::getEncodedSize() {
    return binaryFieldValue.size();
}
