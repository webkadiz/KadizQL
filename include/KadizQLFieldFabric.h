#include "KadizQLField.h"
#include "KadizQLFieldScheme.h"
#include "KadizQL.h"

namespace KadizQL {
    class FieldFabric {
    public:
        static Field *createField(dataTypes, FieldScheme *);
    };
}