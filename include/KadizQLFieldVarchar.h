#pragma once

#include <variant>
#include <string>
#include "KadizQLField.h"

using namespace std;

namespace KadizQL {
    class FieldVarchar: public Field {
        string realFieldValue;
    public:
        FieldVarchar(string, FieldScheme *);
        void processedValue();
        dataTypes data();
    };
}