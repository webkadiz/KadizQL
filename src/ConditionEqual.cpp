#include "../include/ConditionEqual.h"

using namespace KadizQL;

ConditionEqual::ConditionEqual(string fieldName, dataTypes fieldValue) {
    this->fieldName = fieldName;
    this->fieldValue = fieldValue;
}

bool ConditionEqual::exec(Row &row) {
    if (row[fieldName]) {
        if (row[fieldName]->data() == fieldValue) return true;
        else return false;
    }

    throw std::exception();
} 