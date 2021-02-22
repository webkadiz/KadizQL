#include <iostream>
#include <filesystem>
#include "../include/KadizQLRDBMS.h"
#include "../include/KadizQLDB.h"

namespace fs = std::filesystem;
using namespace KadizQL;

int main() {
    RDBMS::setBaseDirName(".kadizql-test");
    fs::remove_all(RDBMS::getBaseDir());

    DB::createDB("test");

    if (fs::exists(RDBMS::getBaseDir() / "test")) {
        printf("test 1 passed\n");
    } else {
        printf("test 1 failed\n");
        exit(1);
    }

    return 0;
}