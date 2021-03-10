#pragma once

#include <string>
#include <variant>
#include "KadizQL.h"
#include "KadizQLFieldScheme.h"

using namespace std;

namespace KadizQL {
    class Field {
    protected:
        FieldScheme *fieldScheme;
    public:
        Field(FieldScheme *);
        virtual ~Field();
        string getName();
        virtual dataTypes data() = 0;
        virtual char *getEncodedData() = 0;
        virtual size_t getEncodedSize() = 0;
    };
}