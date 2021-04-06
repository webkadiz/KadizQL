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
        string trueStr = "some text";

        trueStr.resize(255);
 
        if (get<string>(fieldText.data()) == trueStr) {
            testPassed(testNumber);
        } else {
            testFailed(testNumber);
        }

        if (get<string>(&fieldText) == trueStr) {
            testPassed(testNumber);
        } else {
            testFailed(testNumber);
        }
    }
}
