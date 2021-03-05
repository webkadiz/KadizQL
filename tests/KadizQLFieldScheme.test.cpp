#include <iostream>
#include "../include/KadizQLFieldScheme.h"

using namespace std;
using namespace KadizQL;

int main() {
    {
        // name for column doesn't exists

        try {
            FieldScheme fieldScheme({});

            cout << "test 1 failed";
            exit(1);
        } catch(std::exception &e) {
            cout << "test 1 passed" << endl;
        }
    }

    {
        // type for column doesn't exists

        try {
            FieldScheme fieldScheme({"id"});

            cout << "test 2 failed";
            exit(2);
        } catch(std::exception &e) {
            cout << "test 2 passed" << endl;
        }
    }

    {
        // type for column wrong

        try {
            FieldScheme fieldScheme({"id", "abrakadabra"});

            cout << "test 3 failed";
            exit(3);
        } catch(std::exception &e) {
            cout << "test 3 passed" << endl;
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
            cout << "test 4 passed" << endl;
        } else {
            cout << "test 4 failed";
            exit(4);
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
            cout << "test 5 passed" << endl;
        } else {
            cout << "test 5 failed";
            exit(5);
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
            cout << "test 6 passed" << endl;
        } else {
            cout << "test 6 failed";
            exit(6);
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
            cout << "test 7 passed" << endl;
        } else {
            cout << "test 7 failed";
            exit(7);
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
            cout << "test 8 passed" << endl;
        } else {
            cout << "test 8 failed";
            exit(8);
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
            cout << "test 9 passed" << endl;
        } else {
            cout << "test 9 failed";
            exit(9);
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
            cout << "test 10 passed" << endl;
        } else {
            cout << "test 10 failed";
            exit(10);
        }
    }

    {
        // test on name register

        FieldScheme fieldScheme({"id", "Date"});

        if (fieldScheme.getName() == "ID") {
            cout << "test 11 passed" << endl;
        } else {
            cout << "test 11 failed";
            exit(11);
        }
    }

    {
        // test on name register type

        FieldScheme fieldScheme({"id", "Date"});

        if (fieldScheme.getType() == "DATE") {
            cout << "test 12 passed" << endl;
        } else {
            cout << "test 12 failed";
            exit(12);
        }
    }
}