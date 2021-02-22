#include <string>
#include <filesystem>
#include "../include/KadizQLRDBMS.h"

using namespace KadizQL;
namespace fs = std::filesystem;

fs::path RDBMS::getBaseDir() {
    fs::path homeDir = getenv("HOME");
    fs::path baseDir = homeDir / baseDirName;

    return baseDir;
}

void RDBMS::setBaseDirName(string dirName) {
    baseDirName = dirName;
}