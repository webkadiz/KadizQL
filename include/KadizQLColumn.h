#pragma once
#include <string>
#include <vector>

using namespace std;

namespace KadizQL {
    class Column {
        static const vector<string> TYPES;
        vector<string> fields;
        bool isNotNull = false;
        bool isDefault = false;
        bool isAutoIncrement = false;
        bool isPrimaryKey = false;
        string type;
        string name;
    public:
        Column(vector<string>);
        vector<string> getFields();
        bool processFields();        
        void processName(int &);
        void processType(int &);
        void processNotNull(int &);
        void processDefault(int &);
        void processAutoIncrement(int &);
        void processPrimaryKey(int &);
    };
}