#pragma once
#include <vector>
#include <map>
#include "KadizQLField.h"

using namespace std;

namespace KadizQL {
    class Row {
        vector<Field *> row;
        map<string, Field *> fieldMap;
    public:
        Row();
        Row(vector<Field *>);

        Field *operator[](string);
        void addField(Field *);
    };
}