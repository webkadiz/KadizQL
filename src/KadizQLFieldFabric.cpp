#include "../include/KadizQLFieldFabric.h"
#include "../include/KadizQLFieldInt.h"
#include "../include/KadizQLField.h"

using namespace KadizQL;

Field *FieldFabric::createField(string fieldValue, FieldScheme &fieldScheme) {
    if (fieldScheme.getType() == "INT") {
        return new FieldInt(fieldValue, fieldScheme);
    } else {
        throw std::exception();
    }
}