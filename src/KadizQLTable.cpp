#include <string>
#include <iostream>
#include <fstream>
#include "../include/KadizQLTable.h"

using namespace std;
using namespace KadizQL;

string Table::readTableFromFile(string filename) {
    string fileContent, line;
    ifstream file;
    
    file.open(filename);

    if (file.is_open()) {
        while(getline(file, line)) fileContent += line + "\n";
        file.close();
        return fileContent;
    } else {
        cout << "Error: file " + filename + " not open";
        fileContent = "";
        return fileContent;
    }
}

void Table::readTable() {

}

void Table::writeTable() {

}
