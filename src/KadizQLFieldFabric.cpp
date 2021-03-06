#include "../include/KadizQLFieldFabric.h"
#include "../include/KadizQLFieldInt.h"
#include "../include/KadizQLFieldText.h"
#include "../include/KadizQLField.h"
#include "../include/utils.h"

using namespace KadizQL;

Field *FieldFabric::createField(string fieldValue, string type) {
    type = toUpperCase(type);

    if (type == "INT") {
        return new FieldInt(fieldValue);
    } else if (type == "TEXT") {
        return new FieldText(fieldValue);
    } else {
        throw std::exception();
    }
}