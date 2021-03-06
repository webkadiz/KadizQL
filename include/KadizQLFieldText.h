#pragma once

#include <variant>
#include <string>
#include "KadizQLField.h"

using namespace std;

namespace KadizQL {
    class FieldText: public Field {
        string binaryFieldValue;
    public:
        FieldText(string);
        dataTypes data();
        string getType();
        char *getEncodedData();
        size_t getEncodedSize();
    };
}