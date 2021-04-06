#include "../include/KadizQLFieldFabric.h"
#include "../include/KadizQLFieldInt.h"
#include "../include/KadizQLFieldText.h"
#include "../include/KadizQLField.h"

using namespace KadizQL;

Field *FieldFabric::createField(string fieldValue, FieldScheme *fieldScheme) {
    if (fieldScheme->getType() == "INT") {
        return new FieldInt(fieldValue);
    } else if (fieldScheme->getType() == "TEXT") {
        return new FieldText(fieldValue);
    } else {
        throw std::exception();
    }
}