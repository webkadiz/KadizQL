#include "../include/KadizQLFieldNull.h"
#include "../include/utils.h"

using namespace KadizQL;
using namespace std;

int main() {
    size_t testNumber = 0;

    {
        FieldNull fieldNull("int");

        if (fieldNull.getEncodedSize() == 4) {
            testPassed(testNumber);
        } else {
            testFailed(testNumber);
        }
    }
    return 0;
}