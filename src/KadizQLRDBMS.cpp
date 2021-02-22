#include <string>
#include <filesystem>
#include "../include/KadizQLRDBMS.h"

namespace fs = std::filesystem;
using namespace KadizQL;

fs::path RDBMS::getBaseDir() {
    fs::path homeDir = getenv("HOME");
    fs::path baseDir = homeDir / baseDirName;

    return baseDir;
}

void RDBMS::setBaseDirName(string dirName) {
    baseDirName = dirName;
}