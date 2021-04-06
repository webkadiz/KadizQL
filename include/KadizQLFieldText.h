#pragma once

#include <variant>
#include <string>
#include "KadizQLField.h"

using namespace std;

namespace KadizQL {
    class FieldText: public Field {
        char binaryFieldValue[255];
        string stringFieldValue;
    public:
        FieldText(string);
        dataTypes data();
        char *getEncodedData();
        size_t getEncodedSize();
    };
}