#include "../include/KadizQLDB.h"
#include "../include/KadizQLTable.h"
#include "../include/KadizQLResult.h"
#include "../include/KadizQLFieldInt.h"
#include "../include/KadizQLFieldText.h"
#include "../include/KadizQLFieldNull.h"
#include "../include/ConditionFalse.h"
#include "../include/ConditionEqual.h"
#include "../include/utils.h"

using namespace KadizQL;

int main() {
    size_t testNumber = 0;

    DB::useDB("test");

    Table *table = new Table("table");

    table->create({
        {"id", "int", "not null"},
        {"name", "text"}
    });

    {
        Row row;
        Result res;

        Field *id = new FieldInt(123);
        Field *name = new FieldText("alex"); 

        row.add(id, "id");
        row.add(name, "name");

        res = table->insert(row);

        if (res.getAffectedRowsCount() == 0) {
            testFailed(testNumber);
        }

        testPassed(testNumber);
    }

    {
        Result res = table->select({"id"});

        if (get<int>(res["id"]) == 123) {
            testPassed(testNumber);
        } else {
            testFailed(testNumber);
        }
    }

    {
        Row row;
        Result res;

        row.add(new FieldInt(124), "id");
        row.add(new FieldNull("text"), "name");

        res = table->insert(row);

        if (res.getAffectedRowsCount() == 0) {
            testFailed(testNumber);
        }

        testPassed(testNumber);
    }

    {
        Result res = table->select({"id"});

        if (get<int>(res[1]["id"]) == 124) {
            testPassed(testNumber);
        } else {
            testFailed(testNumber);
        }
    }

    {
        Result res = table->select({"id"}, new ConditionFalse());

        if (res.size() == 0) {
            testPassed(testNumber);
        } else {
            testFailed(testNumber);
        }
    }

    {
        Result res = table->select({"id"}, new ConditionEqual("id", 123));

        if (res.size() == 1 &&
            res[0].length() == 1 &&
            get<int>(res["id"]) == 123
        ) {
            testPassed(testNumber);
        } else {
            testFailed(testNumber);
        }
    }

    {
        Result res = table->update("id", new FieldInt(125), new ConditionEqual("id", 124));

        if (res.getAffectedRowsCount() == 1) {
            testPassed(testNumber);
        } else {
            testFailed(testNumber);
        }

        res = table->select({"id"});

        if (res.size() == 2 &&
            get<int>(res[1]["id"]) == 125 &&
            get<int>(res[0]["id"]) == 123
        ) {
            testPassed(testNumber);
        } else {
            testFailed(testNumber);
        }
    }

    {
        Result res;

        res = table->remove(new ConditionEqual("id", 125));

        if (res.getAffectedRowsCount() == 1) {
            testPassed(testNumber);
        } else {
            testFailed(testNumber);
        }

        res = table->select({"id"});

        if (res.size() == 1 &&
            get<int>(res["id"]) == 123
        ) {
            testPassed(testNumber);
        } else {
            testFailed(testNumber);
        }
    }

    {
        Result res;

        res = table->remove();

        if (res.getAffectedRowsCount() == 1) {
            testPassed(testNumber);
        } else {
            testFailed(testNumber);
        }

        res = table->select({"id"});

        if (res.size() == 0) {
            testPassed(testNumber);
        } else {
            testFailed(testNumber);
        }
    }

    return 0;
}