#pragma once
#include <string>
#include <iostream>
#include <filesystem>

namespace fs = std::filesystem;
using namespace std;

namespace KadizQL {
    class DB {
        string usedDB;
    public:
        int createDBDir(string dirName);
        int createDB(string dbName);
    };
}
