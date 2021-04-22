#include <string>
#include "../include/KadizQLFieldNull.h"
#include "../include/KadizQLFieldFabric.h"

using namespace std;
using namespace KadizQL;

FieldNull::FieldNull(string type) {
    pretendField = FieldFabric::createField("", type);
}

dataTypes FieldNull::data() {
    return (dataTypes) pretendField->data();
}

string FieldNull::getType() {
    return pretendField->getType();
}

char *FieldNull::getEncodedData() {
    return pretendField->getEncodedData();
}

size_t FieldNull::getEncodedSize() {
    return pretendField->getEncodedSize();
}
