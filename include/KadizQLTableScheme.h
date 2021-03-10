#pragma once
#include <vector>
#include "KadizQLFieldScheme.h"

namespace KadizQL {
    class TableScheme {
        vector<FieldScheme *> fieldSchemes;
    public:
        TableScheme();
        TableScheme(vector<vector<string>>);
        int getFieldOffsetByName(string);
        FieldScheme *operator[](size_t);
        FieldScheme *at(size_t);
        void at(size_t, FieldScheme *);
        size_t length();
    };
}