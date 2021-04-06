#include <string>
#include <iostream>
#include "../include/KadizQLResult.h"
#include "../include/KadizQLRow.h"
#include "../include/KadizQLField.h"
#include "../include/KadizQLFieldInt.h"
#include "../include/KadizQLFieldText.h"
#include "../include/utils.h"

using namespace std;
using namespace KadizQL;

int main() {
    size_t testNumber = 0;

    Row row;

    int id = 1;
    string name = "1";

    Field *fieldId = new FieldInt(id);
    Field *fieldName = new FieldText(name);

    row.add(fieldId, "id");
    row.add(fieldName, "name");

    {
        Result result;

        result.add(row);

        if (result["ID"] == nullptr || result["name"] == nullptr) {
            testFailed(testNumber);
        }

        testPassed(testNumber);
    }

    {
        Result result;

        result.add(row);
        result.add(row);

        name.resize(255);

        if (result[0]["id"] == nullptr ||
            get<int>(result[0]["id"]) != id ||
            get<string>(result[0]["name"]) != name
        ) {
            testFailed(testNumber);
        }

        testPassed(testNumber);
    }

    return 0;
}