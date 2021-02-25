#include "../include/KadizQLField.h"
#include "../include/KadizQLFieldInt.h"
#include "../include/KadizQLFieldScheme.h"
#include <iostream>

using namespace std;
using namespace KadizQL;

int main() {
    FieldScheme fieldScheme ({"id", "int"});
    Field field {"123", fieldScheme};
    FieldInt fieldInt ("124", fieldScheme);
    FieldInt *fieldIntPtr;

    cout << "fieldInt " << fieldInt.getValue() << endl;

    fieldIntPtr = (FieldInt *) &field;

    cout << fieldIntPtr->getValue() << endl;
}