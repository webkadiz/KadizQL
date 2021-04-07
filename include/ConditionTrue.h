#pragma once
#include "KadizQLRow.h"
#include "Condition.h"

namespace KadizQL {
    class ConditionTrue: public Condition {
    public:
        bool exec(Row &);
    };
}