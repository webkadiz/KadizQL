#include <string>
#include <iostream>
#include <filesystem>
#include "../include/KadizQLRDBMS.h"
#include "../include/KadizQLDB.h"

namespace fs = std::filesystem;
using namespace std;
using namespace KadizQL;

int DB::createDBDir(string dirName) {
    fs::path baseDir = RDBMS::getBaseDir();
    fs::path dbDirName = baseDir / dirName;

    if (fs::exists(dbDirName)) {
        cout << "db dir exists";
    } else {
        cout << "db dir not exists";
    }
    cout << dbDirName;
}

int DB::createDB(string dbName) {
    this->createDBDir(dbName);
}