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
    bool createDirStatus;

    if (fs::exists(dbDirName)) {
        cout << "db dir exists";
    } else if (fs::exists(baseDir)) {
        bool createDirStatus = fs::create_directory(dbDirName);
        cout << "db dir create status " << createDirStatus;
    } else {
        try {
            createDirStatus = fs::create_directory(baseDir);
            cout << "db dir create status " << createDirStatus;
            createDirStatus = fs::create_directory(dbDirName);
            cout << "db dir create status " << createDirStatus;
        } catch(std::filesystem::filesystem_error& e) {
            cout << e.what();
        }
    }
}

int DB::createDB(string dbName) {
    createDBDir(dbName);
}