#include "KadizQL.cpp"
#include <string>
#include <iostream>
#include <filesystem>

namespace fs = std::filesystem;

class KadizQLDB {

public:
    int createDBDir(std::string dirName) {
        std::string baseDir = KadizQL::getBaseDir();
        std::string dbDirName = baseDir + dirName;

        if (fs::exists(dbDirName)) {
            std::cout << "db dir exists";
        } else {
            std::cout << "db dir not exists";
        }
        std::cout << dbDirName;
    }

    int createDB(std::string dbName) {
        this->createDBDir(dbName);
    }
};