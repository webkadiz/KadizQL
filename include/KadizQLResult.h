#pragma once
#include <string>
#include <vector>
#include "KadizQLField.h"
#include "KadizQLRow.h"

using namespace std;

namespace KadizQL {
    class Result {
        vector<Row> resultRows;
        size_t affectedRowsCount;
    public:
        Result();
        Field *operator[](string);
        Row operator[](size_t);
        size_t size();
        void add(Row);
        size_t getAffectedRowsCount();
        void incAffectedRowsCount();
    };
}