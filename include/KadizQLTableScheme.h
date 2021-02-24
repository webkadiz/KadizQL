#include "KadizQLFieldScheme.h"

namespace KadizQL {
    class TableScheme {
        vector<FieldScheme *> fieldSchemes;
    public:
        void addFieldScheme(FieldScheme *) noexcept;
    };
}