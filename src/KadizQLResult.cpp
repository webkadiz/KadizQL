#include <iostream>
#include <string>
#include "../include/KadizQLResult.h"
#include "../include/KadizQLField.h"

using namespace std;
using namespace KadizQL;

Field *Result::operator[](string key) {
        
}

Row Result::operator[](size_t idx) {
    return this->rows.at(idx);
}

void Result::addRow(Row row) {
    this->rows.push_back(row);
}