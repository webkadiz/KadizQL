#pragma once
#include <string>
#include <vector>

using namespace std;

namespace KadizQL {
    class FieldScheme {
        static const vector<string> TYPES;
        vector<string> params;
        vector<string> processedParams;
        bool isNotNull = false;
        bool isDefault = false;
        bool isAutoIncrement = false;
        bool isPrimaryKey = false;
        string type;
        string name;
    public:
        FieldScheme();
        FieldScheme(vector<string>);
        string getName();
        vector<string> getParams();
        vector<string> getProcessedParams();
        bool processParams();
        void processName(int &);
        void processType(int &);
        void processNotNull(int &);
        void processDefault(int &);
        void processAutoIncrement(int &);
        void processPrimaryKey(int &);
    };
}