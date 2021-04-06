#include "../include/KadizQLFieldScheme.h"
#include "../include/utils.h"

using namespace std;
using namespace KadizQL;

int main() {
    size_t testNumber = 0;

    {
        // name for column doesn't exists

        try {
            FieldScheme fieldScheme({});

            testFailed(testNumber);
        } catch(std::exception &e) {
            testPassed(testNumber);
        }
    }

    {
        // type for column doesn't exists

        try {
            FieldScheme fieldScheme({"id"});

            testFailed(testNumber);
        } catch(std::exception &e) {
            testPassed(testNumber);
        }
    }

    {
        // type for column wrong

        try {
            FieldScheme fieldScheme({"id", "abrakadabra"});

            testFailed(testNumber);
        } catch(std::exception &e) {
            testPassed(testNumber);
        }
    }

    {
        // simple type description, optional params not used

        FieldScheme fieldScheme({"id", "date"});

        if (
            fieldScheme.isNotNull() == false &&
            fieldScheme.isDefault() == false &&
            fieldScheme.isAutoIncrement() == false &&
            fieldScheme.isPrimaryKey() == false
        ) {
            testPassed(testNumber);
        } else {
            testFailed(testNumber);
        }
    }

    {
        // optional param "not null" used

        FieldScheme fieldScheme({"id", "date", "not null"});

        if (
            fieldScheme.isNotNull() == true &&
            fieldScheme.isDefault() == false &&
            fieldScheme.isAutoIncrement() == false &&
            fieldScheme.isPrimaryKey() == false
        ) {
            testPassed(testNumber);
        } else {
            testFailed(testNumber);
        }
    }

    {
        // optional param "default" used

        FieldScheme fieldScheme({"id", "date", "default 123"});

        if (
            fieldScheme.isNotNull() == false &&
            fieldScheme.isDefault() == true &&
            fieldScheme.isAutoIncrement() == false &&
            fieldScheme.isPrimaryKey() == false
        ) {
            testPassed(testNumber);
        } else {
            testFailed(testNumber);
        }
    }

    {
        // optional param "auto increment" used

        FieldScheme fieldScheme({"id", "date", "auto increment"});

        if (
            fieldScheme.isNotNull() == false &&
            fieldScheme.isDefault() == false &&
            fieldScheme.isAutoIncrement() == true &&
            fieldScheme.isPrimaryKey() == false
        ) {
            testPassed(testNumber);
        } else {
            testFailed(testNumber);
        }
    }

    {
        // optional param "primary key" used

        FieldScheme fieldScheme({"id", "date", "primary key"});

        if (
            fieldScheme.isNotNull() == false &&
            fieldScheme.isDefault() == false &&
            fieldScheme.isAutoIncrement() == false &&
            fieldScheme.isPrimaryKey() == true
        ) {
            testPassed(testNumber);
        } else {
            testFailed(testNumber);
        }
    }

    {
        // optional param "not null", "primary key" used

        FieldScheme fieldScheme({"id", "date", "not null", "primary key"});

        if (
            fieldScheme.isNotNull() == true &&
            fieldScheme.isDefault() == false &&
            fieldScheme.isAutoIncrement() == false &&
            fieldScheme.isPrimaryKey() == true
        ) {
            testPassed(testNumber);
        } else {
            testFailed(testNumber);
        }
    }

    {
        // test on register

        FieldScheme fieldScheme({"ID", "Date", "NOT null", "priMary key"});

        if (
            fieldScheme.isNotNull() == true &&
            fieldScheme.isDefault() == false &&
            fieldScheme.isAutoIncrement() == false &&
            fieldScheme.isPrimaryKey() == true
        ) {
            testPassed(testNumber);
        } else {
            testFailed(testNumber);
        }
    }

    {
        // test on name register

        FieldScheme fieldScheme({"id", "Date"});

        if (fieldScheme.getName() == "ID") {
            testPassed(testNumber);
        } else {
            testFailed(testNumber);
        }
    }

    {
        // test on name register type

        FieldScheme fieldScheme({"id", "Date"});

        if (fieldScheme.getType() == "DATE") {
            testPassed(testNumber);
        } else {
            testFailed(testNumber);
        }
    }
}