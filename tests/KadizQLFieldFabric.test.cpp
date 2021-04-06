#include <iostream>
#include <string>
#include "../include/KadizQL.h"
#include "../include/KadizQLFieldFabric.h"
#include "../include/KadizQLFieldInt.h"
#include "../include/KadizQLFieldText.h"
#include "../include/KadizQLField.h"
#include "../include/utils.h"

using namespace std;
using namespace KadizQL;

int main() {
    size_t testNumber = 0;

    string fieldValueForInt = "123";
    string fieldValueForVarchar = "some text\n";

    Field *fieldInt = FieldFabric::createField(fieldValueForInt, "int");
    Field *fieldVarchar = FieldFabric::createField(fieldValueForVarchar, "text");

    try {
        get<int>(fieldInt->data());
        get<string>(fieldVarchar->data());

        testPassed(testNumber);
    } catch(bad_variant_access &e) {
        testFailed(testNumber);
    }
}
