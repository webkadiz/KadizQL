#include <filesystem>
#include "../include/KadizQLRDBMS.h"
#include "../include/KadizQLDB.h"

namespace fs = std::filesystem;
using namespace KadizQL;

int main() {
    RDBMS::setBaseDirName(".kadizql-test");

    fs::remove_all(RDBMS::getBaseDir());
    
    DB::createDB("test");

    return 0;
}