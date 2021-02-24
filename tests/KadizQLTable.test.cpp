#include "../include/KadizQLDB.h"
#include "../include/KadizQLTable.h"

using namespace KadizQL;

int main() {
    DB::useDB("test");

    Table *table = new Table("name");

    table->create({
        {"id", "int", "date"}
    });

    table->load();
}