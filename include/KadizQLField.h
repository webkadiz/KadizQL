#pragma once

#include <string>
#include <variant>
#include "KadizQL.h"
#include "KadizQLFieldScheme.h"

using namespace std;

namespace KadizQL {
    class Field {
    protected:
    public:
        virtual ~Field();
        virtual dataTypes data() = 0;
        virtual string getType() = 0;
        virtual char *getEncodedData() = 0;
        virtual size_t getEncodedSize() = 0;
    };
}