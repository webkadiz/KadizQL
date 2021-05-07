#pragma once
#include <vector>
#include "KadizQLField.h"

namespace KadizQL {
    class FieldNull: public Field {
        Field *pretendField;
    public:
        FieldNull();
        dataTypes data();
        string getType();
        char *getEncodedData();
        size_t getEncodedSize();
    };
}