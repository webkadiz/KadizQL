#include <iostream>
#include "../include/KadizQLRow.h"
#include "../include/KadizQLField.h"
#include "../include/KadizQLFieldInt.h"
#include "../include/KadizQLFieldText.h"
#include "../include/utils.h"

using namespace std;
using namespace KadizQL;

int main() {
    size_t testNumber = 0;
    Field *fieldId = new FieldInt("1");
    Field *fieldId2 = new FieldInt("1");
    Field *fieldName = new FieldText("some text");

    {
        Row row;

        row.add(fieldId, "id");
        row.add(fieldName, "name");

        if (row["id"] == nullptr || 
            row["name"] == nullptr ||
            row["NAME"] == nullptr ||
            row["Id"] == nullptr
        ) {
            testFailed(testNumber);
        }
        testPassed(testNumber);
    }

    {
        Row row;

        try {
            row.add(fieldId, "id");
            row.add(fieldId, "id");
            testFailed(testNumber);
        } catch(exception &e) {
            testPassed(testNumber);
        }
    }

    {
        Row row;

        if (row["undefined"] == nullptr) {
            testPassed(testNumber);
        } else {
            testFailed(testNumber);
        }
    }

    {
        Row row;

        row.add(fieldId, "id");
        row.add(fieldName, "name");

        row.at("id", fieldId2);

        if (row[0] == fieldId2) {
            testPassed(testNumber);
        } else {
            testFailed(testNumber);
        }
    }

    {
        Row row;

        row.add(fieldId, "id");
        row.add(fieldName, "name");

        row.at(0, fieldId2);

        if (row["id"] == fieldId2) {
            testPassed(testNumber);
        } else {
            testFailed(testNumber);
        }
    }

    return 0;
}