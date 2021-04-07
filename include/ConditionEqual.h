#pragma once
#include "KadizQLRow.h"
#include "Condition.h"

namespace KadizQL {
    class ConditionEqual: public Condition {
    public:
        bool exec(Row &);
    };
}