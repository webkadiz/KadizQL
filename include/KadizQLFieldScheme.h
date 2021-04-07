#pragma once
#include <string>
#include <vector>

using namespace std;

namespace KadizQL {
    class FieldScheme {
        static const vector<string> TYPES;
        vector<string> params;
        vector<string> processedParams;
        string name;
        string type;
        bool _isNotNull;
        bool _isDefault;
        bool _isAutoIncrement;
        bool _isPrimaryKey;
        size_t paramIter;
    public:
        FieldScheme(vector<string>);
        string getName();
        string getType();
        bool isNotNull();
        bool isDefault();
        bool isAutoIncrement();
        bool isPrimaryKey();
        size_t getEncodedSize();
        vector<string> getParams();
        vector<string> getProcessedParams();
        void processParams();
    private:
        void processName();
        void processType();
        void processNotNull();
        void processDefault();
        void processAutoIncrement();
        void processPrimaryKey();
    };
}