#include <cassert>
#include <iostream>
#include "../include/KadizQLRow.h"
#include "../include/KadizQLFieldFabric.h"
#include "../include/KadizQLField.h"
#include "../include/KadizQLFieldScheme.h"

using namespace std;
using namespace KadizQL;

int main() {
    FieldScheme *fieldSchemeId = new FieldScheme({"id", "int"});
    FieldScheme *fieldSchemeName = new FieldScheme({"name", "varchar"});

    Field *fieldId = FieldFabric::createField("1", fieldSchemeId);
    Field *fieldName = FieldFabric::createField("name", fieldSchemeName);

    {
        Row row;

        row.addField(fieldId);
        row.addField(fieldName);

        assert(row["id"] != nullptr);
        assert(row["name"] != nullptr);
        assert(row["NAME"] != nullptr);
        assert(row["Id"] != nullptr);
        cout << "test passed" << endl;
    }

    {
        Row row;

        try {
            row.addField(fieldId);
            row.addField(fieldId);
            assert(("dublicated field type", false));
        } catch(exception &e) {
            cout << "test passed" << endl;
        }
    }

    {
        Row row;

        row.addField(fieldId);

        *row["id"] = *fieldName;
    }
    
    return 0;
}