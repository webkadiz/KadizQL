#pragma once

#include <string>
#include <variant>
#include "KadizQL.h"
#include "KadizQLFieldScheme.h"

using namespace std;

namespace KadizQL {
    class Field {
    protected:
        string fieldValue;
        FieldScheme *fieldScheme;
    public:
        Field(string, FieldScheme *);
        virtual ~Field();
        string getName();
        virtual dataTypes data() = 0;
    };
}