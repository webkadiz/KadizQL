#pragma once
#include "KadizQLRow.h"
#include "Condition.h"

namespace KadizQL {
    class ConditionEqual: public Condition {
        string fieldName;
        dataTypes fieldValue;
    public:
        ConditionEqual(string, dataTypes);
        bool exec(Row &);
    };
}