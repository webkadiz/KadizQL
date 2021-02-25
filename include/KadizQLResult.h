#pragma once
#include <string>
#include <vector>
#include "KadizQLField.h"
#include "KadizQLRow.h"

using namespace std;

namespace KadizQL {
    class Result {
        vector<Row> rows;
    public:
        Field *operator[](string);
        Row operator[](size_t);
        void addRow(Row);
    };
}