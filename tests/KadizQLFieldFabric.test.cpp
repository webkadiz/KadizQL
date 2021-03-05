#include <iostream>
#include <string>
#include "../include/KadizQL.h"
#include "../include/KadizQLFieldScheme.h"
#include "../include/KadizQLFieldFabric.h"
#include "../include/KadizQLFieldInt.h"
#include "../include/KadizQLFieldVarchar.h"
#include "../include/KadizQLField.h"
#include "../include/utils.h"

using namespace std;
using namespace KadizQL;

int main() {
    FieldScheme *fieldSchemeForInt = new FieldScheme({"id", "int"});
    FieldScheme *fieldSchemeForVarchar = new FieldScheme({"id", "varchar"});
    string fieldValueForInt = "123";
    string fieldValueForVarchar = "some text\n";
    Field *fieldInt, *fieldVarchar;

    fieldInt = FieldFabric::createField(fieldValueForInt, fieldSchemeForInt);
    fieldVarchar = FieldFabric::createField(fieldValueForVarchar, fieldSchemeForVarchar);

    try {
        get<int>(fieldInt->data());
        get<string>(fieldVarchar->data());

        cout << "test 1 passed" << endl;
    } catch(bad_variant_access &e) {
        cout << "test 1 failed" << endl;
        exit(1);
    }

    try {
        get<int>(fieldInt);
        get<string>(fieldVarchar);

        cout << "test 2 passed" << endl;
    } catch(bad_variant_access &e) {
        cout << "test 2 failed" << endl;
        exit(2);
    }
}
