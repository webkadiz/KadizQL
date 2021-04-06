#include "../include/KadizQLDB.h"
#include "../include/KadizQLTable.h"
#include "../include/KadizQLResult.h"
#include "../include/KadizQLFieldInt.h"
#include "../include/KadizQLFieldVarchar.h"
#include "../include/utils.h"

using namespace KadizQL;

int main() {
    size_t testCount = 0;

    DB::useDB("test");

    Table *table = new Table("name");

    table->create({
        {"id", "int", "not null"},
        {"name", "text"}
    });

    // table->loadScheme();

    Result res = table->select({"id"});

    // if (get<int>(res[0]["id"]) == 12) {
    //     testPassed(testCount);
    // } else {
    //     testFailed(testCount);
    // }

    // if (get<int>(res[1]["id"]) == 555) {
    //     testPassed(testCount);
    // } else {
    //     testFailed(testCount);
    // }

    {
        TableScheme tableScheme({
            {"id", "int", "not null"},
            {"name", "varchar"}
        });

        Row row({
            new FieldInt(123, tableScheme.at(0)),
            new FieldVarchar("1234", tableScheme.at(1))
        }, tableScheme);
        
        table->insert(row);
    }


    {
        Result res = table->select({"id"});

        cout << res["id"];
    }

    return 0;
}