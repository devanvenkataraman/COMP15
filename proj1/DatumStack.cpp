/*
 *		DatumStack.cpp
 *		COMP15 proj1
 *
 *		Implementation of DatumStack class
 *
 *		Author: Devan Venkataraman
 *		Date: 2/18/2019
 */

#include "Datum.h"
#include "DatumStack.h"
#include <vector>

using namespace std;

// default constructor
DatumStack::DatumStack() {
    length = 0;
}

// constructor when provided an array of Datum
DatumStack::DatumStack(Datum arr[], int size) {
    length = 0;

    for (int i = 0; i < size; i++) {
        push(arr[i]);
    }
}

// destructor
DatumStack::~DatumStack() {
}

// Function isEmpty
// Parameters: none
// Returns: bool
// Does: returns true if stack is empty, false if not
bool DatumStack::isEmpty() {
    return datum_stack.empty();
}

// Function clear
// Parameters: none
// Returns: void
// Does: clears the stack
void DatumStack::clear() {
    datum_stack.clear();
}

// Function size
// Parameters: none
// Returns: int
// Does: returns the size (number of Datum) of the datum stack
int DatumStack::size() {
    return length;
}

// Function top
// Parameters: none
// Returns: Datum
// Does: returns the item at the top of the stack
Datum DatumStack::top() {
    if (isEmpty()) {
        throw runtime_error("empty_stack");
    }

    return datum_stack.back();
}

// Function pop
// Parameters: none
// Returns: void
// Does: Pops the top Datum from the stack
void DatumStack::pop() {
    if (isEmpty()) {
        throw runtime_error("empty_stack");
    }

    datum_stack.pop_back();
    length--;
}

// Function push
// Parameters: Datum
// Returns: void
// Does: pushes a Datum onto top of stack
void DatumStack::push(Datum datum) {
    datum_stack.push_back(datum);
    length++;
}
