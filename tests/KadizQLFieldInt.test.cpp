#include <iostream>
#include "../include/KadizQLFieldScheme.h"
#include "../include/KadizQLFieldInt.h"

using namespace std;
using namespace KadizQL;

int main() {
    FieldScheme *fieldScheme = new FieldScheme ({"id", "int"});
    FieldInt fieldInt("123", fieldScheme);

    if ((int)fieldInt == 123) {
        cout << "test 1 passed" << endl;
    } else {
        cout << "test 1 failed" << endl;
        exit(1);
    }

    if (fieldInt.data() == 123) {
        cout << "test 2 passed" << endl;
    } else {
        cout << "test 2 failed" << endl;
    }
}