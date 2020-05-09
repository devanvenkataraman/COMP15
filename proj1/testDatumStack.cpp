/*
 *		testDatumStack.cpp
 *		COMP15 proj1 - CalcYouLater
 *
 *		Test file for DatumStack
 *
 *		Author: Devan Venkataraman
 *		Date: 2/18/2019
 */

#include <string>
#include <iostream>
#include <sstream>
#include "DatumStack.h"
#include "Datum.h"

using namespace std;

void testIsEmpty(DatumStack &stack_0, DatumStack &stack_1);
void testClear(DatumStack &stack_1);
void testSize(DatumStack &stack_0, DatumStack &stack_1);
void testTop(DatumStack &stack_0, DatumStack &stack_1);
void testPop(DatumStack &stack_0, DatumStack &stack_1);
void testPush(DatumStack &stack_0, DatumStack &stack_1, Datum datum);

int main() {
    // test default constructor
    DatumStack stack0;

    Datum arr1[5] = {Datum(1), Datum("okay"), Datum(true), Datum(false), Datum(24)};
    // test 2nd constructor
    DatumStack stack1(arr1, 5);
    // create Datum for push test
    Datum datum1 = Datum("hello");

    testIsEmpty(stack0, stack1);
    testSize(stack0, stack1);
    testTop(stack0, stack1);
    testPop(stack0, stack1);
    testPush(stack0, stack1, datum1);
    testClear(stack1);

    return 0;
}

// Function testIsEmpty
// Parameters: addresses of two Datum stacks
// Returns: nothing
// Does: Tests isEmpty function
void testIsEmpty(DatumStack &stack_0, DatumStack &stack_1) {
    cout << "Is empty stack empty? ";
    bool result0 = stack_0.isEmpty();
    cout << result0 << endl;

    cout << "Is nonempty stack empty? ";
    bool result1 = stack_1.isEmpty();
    cout << result1 << endl << endl;
}

// Function testClear
// Parameters: address of one Datum stack
// Returns: nothing
// Does: Tests clear function
void testClear(DatumStack &stack_1) {
    cout << "Is stack empty before? ";
    bool result0 = stack_1.isEmpty();
    cout << result0 << endl;
    stack_1.clear();
    cout << "After clearing, is stack empty: ";
    bool result1 = stack_1.isEmpty();
    cout << result1 << endl << endl;
}

// Function testSize
// Parameters: addresses of two Datum stacks
// Returns: nothing
// Does: Tests size function
void testSize(DatumStack &stack_0, DatumStack &stack_1) {
    cout << "Size of empty stack is: " << stack_0.size() << endl;
    cout << "Size of nonempty stack is: " << stack_1.size() << endl << endl;
}

// Function testTop
// Parameters: addresses of two Datum stacks
// Returns: nothing
// Does: Tests top function
void testTop(DatumStack &stack_0, DatumStack &stack_1) {
    // correctly throws runtime_error
    // stack_0.top();
    // avoid unused parameter warning
    stack_0.clear();

    cout << "Top element on stack is: "
    << stack_1.top().toString() << endl << endl;
}

// Function testPop
// Parameters: addresses of two Datum stacks
// Returns: nothing
// Does: Tests pop function
void testPop(DatumStack &stack_0, DatumStack &stack_1) {
    // correctly throws runtime_error
    // stack_0.pop();
    // avoid unused parameter warning
    stack_0.clear();

    cout << "Before, size is: " << stack_1.size()
    << " and top element is: " << stack_1.top().toString() << endl;
    stack_1.pop();
    cout << "After pop, size is: " << stack_1.size()
    << " and top element is: " << stack_1.top().toString() << endl << endl;
}

// Function testPush
// Parameters: addresses of two Datum stacks and Datum
// Returns: nothing
// Does: Tests push function
void testPush(DatumStack &stack_0, DatumStack &stack_1, Datum datum) {
    // test push on nonempty stack
    cout << "Before, size is: " << stack_1.size()
    << " and top element is: " << stack_1.top().toString() << endl;
    stack_1.push(datum);
    cout << "After push, size is: " << stack_1.size()
    << " and top element is: " << stack_1.top().toString() << endl << endl;

    // test push on empty stack
    cout << "Before, size is: " << stack_0.size() << endl;
    stack_0.push(datum);
    cout << "After push, size is: " << stack_0.size()
    << " and top element is: " << stack_0.top().toString() << endl << endl;
}
