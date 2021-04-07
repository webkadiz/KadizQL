#pragma once
#include "KadizQLRow.h"
#include "Condition.h"

namespace KadizQL {
    class ConditionFalse: public Condition {
    public:
        bool exec(Row &);
    };
} 