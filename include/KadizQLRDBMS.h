#pragma once
#include <string>
#include <filesystem>

using namespace std;
namespace fs = std::filesystem;

namespace KadizQL {
    static string baseDirName = ".kadizql";
    class RDBMS {
    public:
        static fs::path getBaseDir();
        static void setBaseDirName(string);
    };
}