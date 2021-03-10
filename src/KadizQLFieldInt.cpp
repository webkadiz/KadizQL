#include <string>
#include <variant>
#include <iostream>
#include "../include/KadizQLFieldInt.h"

using namespace std;
using namespace KadizQL;

FieldInt::FieldInt(const char* fieldValue, FieldScheme *fieldScheme) :
    Field(fieldScheme) {
    for (int i = 0; i < 4; i++) {
        binaryFieldValue[i] = fieldValue[i];
    }
    decode();
}

FieldInt::FieldInt(int fieldValue, FieldScheme *fieldScheme) :
    Field(fieldScheme) {
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

char *FieldInt::getEncodedData() {
    return binaryFieldValue;
}

size_t FieldInt::getEncodedSize() {
    return sizeof(binaryFieldValue);
}
