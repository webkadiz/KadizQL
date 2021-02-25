#pragma once
#include <string>
#include "KadizQLFieldScheme.h"

using namespace std;

namespace KadizQL {
    class Field {
        string fieldValue;
        FieldScheme *fieldScheme;
    public:
        Field(string, FieldScheme *);        
        string getName();
    };
}