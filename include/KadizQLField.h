#pragma once
#include <string>
#include "KadizQLFieldScheme.h"

using namespace std;

namespace KadizQL {
    class Field {
    protected:
        string fieldValue;
        FieldScheme fieldScheme;
    public:
        Field(string, FieldScheme &);        
        ~Field();
        string getName();
    };
}