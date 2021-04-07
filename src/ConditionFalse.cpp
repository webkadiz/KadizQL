#include "../include/ConditionFalse.h"

using namespace KadizQL;

bool ConditionFalse::exec(Row &) {
    return false;
}