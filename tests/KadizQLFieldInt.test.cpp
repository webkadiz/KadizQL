#include <iostream>
#include "../include/KadizQLFieldScheme.h"
#include "../include/KadizQLFieldInt.h"
#include "../include/utils.h"

using namespace std;
using namespace KadizQL;

int main() {
    size_t testNumber = 0;

    {
        FieldInt fieldInt("\6\1\0\0");

        if (get<int>(&fieldInt) == 262) {
            testPassed(testNumber);
        } else {
            testFailed(testNumber);
        }
    }

    {
        FieldInt fieldInt(437);

         if (get<int>(&fieldInt) == 437) {
            testPassed(testNumber);
        } else {
            testFailed(testNumber);
        }
    }
}