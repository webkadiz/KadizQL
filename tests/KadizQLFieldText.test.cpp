#include <iostream>
#include <string>
#include "../include/KadizQLFieldText.h"
#include "../include/utils.h"

using namespace std;
using namespace KadizQL;

int main() {
    size_t testNumber = 0;

    {
        FieldText fieldText("some text");

        if (get<string>(fieldText.data()) == "some text") {
            testPassed(testNumber);
        } else {
            testFailed(testNumber);
        }

        if (get<string>(&fieldText) == "some text") {
            testPassed(testNumber);
        } else {
            testFailed(testNumber);
        }
    }
}
