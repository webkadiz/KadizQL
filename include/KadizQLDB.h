#pragma once
#include <string>
#include <iostream>
#include <filesystem>

using namespace std;
namespace fs = std::filesystem;

namespace KadizQL {
    class DB {
        static string usedDB;
    public:
        static string getUsedDB();
        static void useDB(string);
        static bool createDBDir(string dirName);
        static bool createDB(string dbName);
        static fs::path getDBDir();
    };
}
