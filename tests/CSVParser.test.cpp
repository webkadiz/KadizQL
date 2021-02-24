#include <iostream>
#include <string>
#include <cstdlib>
#include "../include/CSVParser.h"

int main() {
    std::string text;    
    CSVParser *parser = new CSVParser();
    std::vector<std::vector<std::string>> table;


// input:
/*123

321
*/
    text = "123\n\n321\n";

    table = parser->parse(text);

    // test on \n in the end of text
    if (table.size() == 3) {
        printf("test 1 passed\n");
    } else {
        printf("test 1 failed\n", table.size());
        exit(1);
    }

    // test on empty line in text
    if (table[1].size() == 1 && table[1][0] == "") {
        printf("test 2 passed\n");
    } else {
        printf("test 2 failed\n");
        exit(2);
    }

// input:
/*124
"124,"
321
*/
    text = "123\n\"123,\"\n321\n";

    table = parser->parse(text);

    if (table.size() == 3) {
        printf("test 3 passed\n");
    } else {
        printf("test 3 failed\n", table.size());
        exit(3);
    }

    // test on second row with first field = 124, 
    if (
        table[1].size() == 1 &&
        table[1][0].size() == 4 &&
        table[1][0][3] == ','
    ) {
        printf("test 4 passed\n");
    } else {
        std::cout << table[1][0];
        printf("n%d", table[1][0][3] == ',');
        printf("test 4 failed\n", table.size());
        exit(4);
    }

// input:
/*"125","126"
"quote""","""apple"", ""orange"""
"banana"
*/
    text = "\"125\",\"126\"\n\"quote\"\"\",\"\"\"apple\"\", \"\"orange\"\"\"\n\"banana\"\n";

    table = parser->parse(text);

    if (table.size() == 3) {
        printf("test 5 passed\n");
    } else {
        printf("test 5 failed\n", table.size());
        exit(5);
    }

    if (table[0].size() == 2 && table[0][0] == "125") {
        printf("test 6 passed\n");
    } else {
        printf("test 6 failed\n", table.size());
        exit(6);
    }

    if (table[1].size() == 2 && table[1][0] == "quote\"") {
        printf("test 7 passed\n");
    } else {
        printf("test 7 failed\n", table.size());
        exit(7);
    }

    if (table[2].size() == 1 && table[2][0] == "banana") {
        printf("test 8 passed\n");
    } else {
        printf("test 8 failed\n", table.size());
        exit(8);
    }

// input
/*123, "

123
*/
/*
123, "
    ^ here error
*/
    try {

        text = "123, \"\n\n123\n";

        table = parser->parse(text);

        printf("test 9 failed\n");
        exit(9);

    } catch(std::exception &e) {
       printf("test 9 passed\n"); 
    }

// input
/*" 123"" " ,125
*/
/*
" 123"" " ,125
         ^ here error
*/
    try {

        text = "\" 123\"\" \" ,125\n";

        table = parser->parse(text);

        printf("test 10 failed\n");
        exit(10);

    } catch(std::exception &e) {
       printf("test 10 passed\n"); 
    }

// input
/*" 123"" "*/
/*
" 123"" "
         ^ here error
*/
// test on newline in the end text after string token
    try {

        text = "\" 123\"\" \"";

        table = parser->parse(text);

        printf("test 11 failed\n");
        exit(11);

    } catch(std::exception &e) {
       printf("test 11 passed\n");
    }

// input
/*/*
^ here error
*/
// test on newline in the end text after common token
    try {

        text = "";

        table = parser->parse(text);

        printf("test 12 failed\n");
        exit(12);

    } catch(std::exception &e) {
       printf("test 12 passed\n");
    }

// input
/*\n*/
// with empty input must be 1 element
    text = "\n";

    table = parser->parse(text);

    if (table.size() == 1 && table[0].size() == 1) {
        printf("test 13 passed");
    } else {
        printf("test 13 failed\n");
        exit(13);
    }


    return 0;
}