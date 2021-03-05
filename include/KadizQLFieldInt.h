#include <string>
#include <variant>
#include "KadizQLField.h"

using namespace std;

namespace KadizQL {
    class FieldInt: public Field {
        int realFieldValue;
    public:
        FieldInt(string, FieldScheme *);
        void processedValue();
        dataTypes data();
    };
}