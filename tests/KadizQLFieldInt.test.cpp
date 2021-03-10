#include <iostream>
#include "../include/KadizQLFieldScheme.h"
#include "../include/KadizQLFieldInt.h"
#include "../include/utils.h"

using namespace std;
using namespace KadizQL;

int main() {
    FieldScheme *fieldScheme = new FieldScheme({"id", "int"});
    FieldInt fieldInt("\6\1\0\0", fieldScheme);

    if (get<int>(&fieldInt) == 262) {
        cout << "test 1 passed" << endl;
    } else {
        cout << "test 1 failed" << endl;
        exit(1);
    }

    fieldInt.encode();
}