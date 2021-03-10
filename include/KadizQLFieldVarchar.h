#pragma once

#include <variant>
#include <string>
#include "KadizQLField.h"

using namespace std;

namespace KadizQL {
    class FieldVarchar: public Field {
        char binaryFieldValue[255];
        string stringFieldValue;
    public:
        FieldVarchar(string, FieldScheme *);
        dataTypes data();
        char *getEncodedData();
        size_t getEncodedSize();
    };
}