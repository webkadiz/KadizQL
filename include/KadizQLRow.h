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
        vector<string> fieldNamesVector;
        map<string, size_t> fieldNamesMap;
    public:
        Row();
        Row(vector<pair<Field *, string>>);
        Field *operator[](size_t);
        Field *operator[](string);
        Field *at(size_t);
        Field *at(string);
        void at(size_t, Field *);
        void at(string, Field*);
        size_t length();
        void add(Field *, string);
    };
}