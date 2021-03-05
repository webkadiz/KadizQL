#include <iostream>
#include <string>
#include "../include/KadizQLFieldScheme.h"
#include "../include/KadizQLFieldVarchar.h"

using namespace std;
using namespace KadizQL;

int main() {
    {
        FieldScheme fieldScheme({"text", "varchar"});
        FieldVarchar fieldVarchar("some text", fieldScheme);

        if ((string)fieldVarchar == "some text") {
            cout << "test 1 passed" << endl;
        } else {
            cout << "test 1 failed" << endl;
            exit(1);
        }

        if (fieldVarchar.data() == "some text") {
            cout << "test 2 passed" << endl;
        } else {
            cout << "test 2 failed" << endl;
            exit(2);
        }
    }
}