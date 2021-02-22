#include <string>
#include <iostream>
#include <filesystem>
#include "../include/KadizQLRDBMS.h"
#include "../include/KadizQLDB.h"

using namespace std;
using namespace KadizQL;
namespace fs = std::filesystem;


string DB::usedDB = "";

bool DB::createDBDir(string dirName) {
    fs::path baseDir = RDBMS::getBaseDir();
    fs::path dbDirName = baseDir / dirName;
    bool createDirStatus;

    if (fs::exists(dbDirName)) {
        createDirStatus = true;
    } else if (fs::exists(baseDir)) {
        try {
            createDirStatus = fs::create_directory(dbDirName);
        } catch(fs::filesystem_error& e) {
            createDirStatus = false;
        }
    } else {
        try {
            createDirStatus = fs::create_directory(baseDir);
            createDirStatus = fs::create_directory(dbDirName);
        } catch(fs::filesystem_error& e) {
            createDirStatus = false;
        }
    }

    return createDirStatus;
}

bool DB::createDB(string dbName) {
    bool createDirStatus = createDBDir(dbName);

    return createDirStatus;
}


void DB::useDB(string dbName) {
    usedDB = dbName;
}

string DB::getUsedDB() {
    return usedDB;
}

fs::path DB::getDBDir() {
    return RDBMS::getBaseDir() / usedDB;
}