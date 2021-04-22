#pragma once
#include <vector>
#include "KadizQLField.h"

namespace KadizQL {
    class FieldNull: public Field {
        Field *pretendField;
    public:
        FieldNull(string);
        dataTypes data();
        string getType();
        char *getEncodedData();
        size_t getEncodedSize();
    };
}