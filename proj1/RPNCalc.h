/*
 *		RPNCalc.h
 *		COMP15 proj1
 *
 *		Interface of RPNCalc class
 *
 *		Author: Devan Venkataraman
 *		Date: 2/26/2019
 */

#ifndef RPN_CALC_H
#define RPN_CALC_H

#include "DatumStack.h"

#include <vector>
#include <string>
#include <iostream>

using namespace std;

class RPNCalc {

public:
    RPNCalc();
    ~RPNCalc();
    void run();

private:
    // dependent on input source
    void fieldQuery();
    void fieldQuery(istringstream &line);
    void fieldQuery(ifstream &ifs);
    // not dependent on input source, fields all valid queries
    void fieldMostQueries(string input);
    void fieldMostQueries2(string input);
    void fieldMostQueries3(string input);

    bool testInt(string input);
    void pushBool(string input);
    void print();
    void flipBool();
    void duplicate();
    void swap();
    void operate(string input);
    void comparison(string input);
    void rString(string input);
    void exec();
    string dropBraces(string input);
    void file();
    void doIf();

    bool got_int(string s, int *resultp);
    string parseRString(istream &input);

    bool game_on = true;

    DatumStack the_stack;

    int source_index = 0;
};

#endif
