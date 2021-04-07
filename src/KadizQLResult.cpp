#include <iostream>
#include <string>
#include "../include/KadizQLResult.h"
#include "../include/KadizQLField.h"

using namespace std;
using namespace KadizQL;

Result::Result() {
    affectedRowsCount = 0;
}

size_t Result::getAffectedRowsCount() {
    return affectedRowsCount;
}

void Result::incAffectedRowsCount() {
    affectedRowsCount++;
}

Field *Result::operator[](string key) {
    if (resultRows.size() == 1) {
        return resultRows[0][key];
    } else {
        return nullptr;
    }     
}

Row Result::operator[](size_t idx) {
    return resultRows.at(idx);
}

size_t Result::size() {
    return resultRows.size();
}

void Result::add(Row row) {
    resultRows.push_back(row);
}
