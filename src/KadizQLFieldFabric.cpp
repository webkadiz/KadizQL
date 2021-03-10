#include "../include/KadizQLFieldFabric.h"
#include "../include/KadizQLFieldInt.h"
#include "../include/KadizQLFieldVarchar.h"
#include "../include/KadizQLField.h"

using namespace KadizQL;

Field *FieldFabric::createField(dataTypes fieldValue, FieldScheme *fieldScheme) {
    if (fieldScheme->getType() == "INT") {
        return new FieldInt(get<int>(fieldValue), fieldScheme);
    } else if (fieldScheme->getType() == "VARCHAR") {
        return new FieldVarchar(get<string>(fieldValue), fieldScheme);
    } else {
        throw std::exception();
    }
}