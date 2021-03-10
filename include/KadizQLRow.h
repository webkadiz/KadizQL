#pragma once
#include <vector>
#include <map>
#include "KadizQLField.h"
#include "KadizQLTableScheme.h"

using namespace std;

namespace KadizQL {
    class Row {
        vector<Field *> fieldVector;
        map<string, Field *> fieldMap;
        TableScheme tableScheme;
    public:
        Row();
        Row(vector<Field *>, TableScheme);
        Field *operator[](size_t);
        Field *operator[](string);
        Field *at(size_t);
        Field *at(string);
        void at(size_t, Field *);
        void at(string, Field*);
        size_t length();
        void addField(Field *);
    };
}