#pragma once
#include <string>
#include <filesystem>

namespace fs = std::filesystem;
using namespace std;

namespace KadizQL {
    static string baseDirName = ".kadizql";
    class RDBMS {
    public:
        static fs::path getBaseDir();
        static void setBaseDirName(string);
    };
}