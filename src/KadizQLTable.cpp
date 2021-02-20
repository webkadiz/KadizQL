#include <string>
#include <iostream>
#include <fstream>
#include "KadizQL.cpp"

using namespace std;

class KadizQLTable {
public:
    string readTableFromFile(string filename) {
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

    void readTable() {

    }

    void writeTable() {

    }


};

int main() {
    KadizQLTable* kqlTable = new KadizQLTable();

    string content = kqlTable->readTableFromFile("test");

    cout << content;
}