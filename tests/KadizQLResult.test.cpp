#include <string>
#include <cassert>
#include <iostream>
#include "../include/KadizQLResult.h"
#include "../include/KadizQLRow.h"
#include "../include/KadizQLFieldScheme.h"
#include "../include/KadizQLField.h"
#include "../include/KadizQLFieldFabric.h"
#include "../include/utils.h"

using namespace std;
using namespace KadizQL;

int main() {
    Row row;

    FieldScheme *fieldSchemeId = new FieldScheme({"id", "int"});
    FieldScheme *fieldSchemeName = new FieldScheme({"name", "varchar"});

    Field *fieldId = FieldFabric::createField("1", fieldSchemeId);
    Field *fieldName = FieldFabric::createField("1", fieldSchemeName);

    row.addField(fieldId);
    row.addField(fieldName);

    {
        Result result;

        result.addRow(row);

        assert(result["ID"] != nullptr);
        assert(result["TEST"] == nullptr);

        cout << "test passed" << endl;
    }

    {
        Result result;

        result.addRow(row);
        result.addRow(row);

        assert(result[0]["id"] != nullptr);
        assert(get<int>(result[0]["id"]) == 1);
        assert(get<string>(result[0]["name"]) == "1");

        cout << "test passed" << endl;
    }

    return 0;
}