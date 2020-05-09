/*
 *		DatumStack.h
 *		COMP15 proj1
 *
 *		Interface of DatumStack class
 *
 *		Author: Devan Venkataraman
 *		Date: 2/18/2019
 */

#ifndef DATUM_STACK_H
#define DATUM_STACK_H

#include <vector>
#include <string>
#include <iostream>

#include "Datum.h"

using namespace std;

class DatumStack {

public:

    DatumStack();
    DatumStack(Datum arr[], int size);
    ~DatumStack();
    bool isEmpty();
    void clear();
    int size();
    Datum top();
    void pop();
    void push(Datum datum);

private:

    vector<Datum> datum_stack;
    int length;

};

#endif
