#include <iostream>
#include "../include/KadizQLFieldScheme.h"
#include "../include/KadizQLFieldFabric.h"
#include "../include/KadizQLFieldInt.h"
#include "../include/KadizQLField.h"

using namespace std;
using namespace KadizQL;

int main() {
    FieldScheme fieldSchemeForInt({"id", "int"}), fieldSchemeForUnknow({"id", "abrakadabra"});
    string fieldValueForInt = "123", fieldValueForUnknow = "unknow";

    // Field *field = new FieldInt(fieldValueForInt, fieldSchemeForInt);
    Field *field = FieldFabric::createField(fieldValueForInt, fieldSchemeForInt);

    // FieldInt *fieldInt = (FieldInt *)field; 
    cout << field->getValue();
}