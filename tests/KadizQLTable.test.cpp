#include "../include/KadizQLDB.h"
#include "../include/KadizQLTable.h"
#include "../include/KadizQLResult.h"
#include "../include/utils.h"

using namespace KadizQL;

int main() {
    size_t testCount = 0;

    DB::useDB("test");

    Table *table = new Table("name");

    table->create({
        {"id", "int", "not null"}
    });

    table->loadScheme();

    Result res = table->select({"id"});

    if (get<int>(res[0]["id"]) == 12) {
        testPassed(testCount);
    } else {
        testFailed(testCount);
    }

    if (get<int>(res[1]["id"]) == 555) {
        testPassed(testCount);
    } else {
        testFailed(testCount);
    }

    table->insert({
        {"555", "666"}
    });

    return 0;
}