/*
 *
 *  COMP 15 HW 1 Cheshire ConCATenation - no strings attached
 *
 *  testCharArrayList.cpp
 *  Testing File for the sequence CharArrayList class
 *
 *  Written by: Devan Venkataraman
 *          on: 01.30.20
 */

#include <iostream>
#include "CharArrayList.h"
using namespace std;

void testGroupOne(CharArrayList &arr1, CharArrayList &arr2, CharArrayList &arr3);
void testGroupTwo(CharArrayList &arr1, CharArrayList &arr3);
void testIsEmpty(CharArrayList &arr);
void testClear(CharArrayList &arr);
void testPrint(CharArrayList &arr);
void testFirst(CharArrayList &arr);
void testLast(CharArrayList &arr);
void testElementAt(CharArrayList &arr);
void testPushAtBack(CharArrayList &arr);
void testPushAtFront(CharArrayList &arr);
void testInsertAt(CharArrayList &arr);
void testInsertInOrder(CharArrayList &arr);
void testPopFromFront(CharArrayList &arr);
void testPopFromBack(CharArrayList &arr);
void testRemoveAt(CharArrayList &arr);
void testReplaceAt(CharArrayList &arr);
void testConcatenate(CharArrayList &arr, CharArrayList &arr2);
void testShrink(CharArrayList &arr);

int main()
{
    // test default constructor
    CharArrayList arr1;
    // test constructor 2
    CharArrayList arr2('d');
    // test constructor 3
    char array[5] = {'d', 'e', 'v', 'a', 'n'};
    int index = 5;
    CharArrayList arr3(array, index);
    // test copy constructor
    CharArrayList arr4 = arr3;
    // test assignment operator
    arr2 = arr3;

    // test the first group of functions
    testGroupOne(arr1, arr2, arr3);
    // test the second group of functions
    testGroupTwo(arr1, arr3);
}

// Function testGroupOne
// Parameters: Three CharArrayList references
// Returns: nothing
// Does: Tests about half of the required functions
void testGroupOne(CharArrayList &arr1, CharArrayList &arr2, CharArrayList &arr3) {
    testIsEmpty(arr1);
    testIsEmpty(arr2);
    testPrint(arr3);
    testFirst(arr3);
    testLast(arr3);
    testElementAt(arr3);
    testPushAtBack(arr3);
    testPushAtFront(arr3);
}

// Function testGroupTwo
// Parameters: Two CharArrayList references
// Returns: nothing
// Does: Tests the remaining required functions
void testGroupTwo(CharArrayList &arr1, CharArrayList &arr3) {
    testInsertAt(arr3);
    testInsertInOrder(arr3);
    testPopFromFront(arr3);
    testPopFromBack(arr3);
    testRemoveAt(arr3);
    testReplaceAt(arr3);
    testConcatenate(arr3, arr1);
    testShrink(arr3);
    testClear(arr3);
}

// Function testIsEmpty
// Parameters: address of a CharArrayList
// Returns: nothing
// Does: Tests isEmpty function
void testIsEmpty(CharArrayList &arr) {
    arr.isEmpty();
}

// Function testClear
// Parameters: address of a CharArrayList
// Returns: nothing
// Does: Tests clear function
void testClear(CharArrayList &arr) {
    cout << endl << "clear it: " << endl;
    arr.clear();
    arr.print();
}

// Function testPrint
// Parameters: address of a CharArrayList
// Returns: nothing
// Does: Tests print function
void testPrint(CharArrayList &arr) {
    cout << endl << "print it: " << endl;
    arr.print();
}

// Function testFirst
// Parameters: address of a CharArrayList
// Returns: nothing
// Does: Tests first function: one normally, one with exception
void testFirst(CharArrayList &arr) {
    arr.first();

    // correctly throws runtime_error exception
    // arr.clear();
    // arr.first();
}

// Function testFirst
// Parameters: address of a CharArrayList
// Returns: nothing
// Does: Tests last function: one normally, one with exception
void testLast(CharArrayList &arr) {
    arr.last();

    // correctly throws runtime_error exception
    // arr.clear();
    // arr.last();
}

// Function testElementAt
// Parameters: address of a CharArrayList
// Returns: nothing
// Does: Tests isEmpty function: one normally, one with its exception
void testElementAt(CharArrayList &arr) {
    arr.elementAt(4);

    // correctly throws out_of_range exception
    // arr.elementAt(5);
}

// Function testPushAtBack
// Parameters: address of a CharArrayList
// Returns: nothing
// Does: Tests pushAtBack function
void testPushAtBack(CharArrayList &arr) {
    cout << endl << "push s at back: " << endl;
    arr.pushAtBack('s');
    arr.print();
}

// Function testPushAtFront
// Parameters: address of a CharArrayList
// Returns: nothing
// Does: Tests pushAtFront function
void testPushAtFront(CharArrayList &arr) {
    cout << endl << "push s at front: " << endl;
    arr.pushAtFront('s');
    arr.print();
}

// Function insertAt
// Parameters: address of a CharArrayList
// Returns: nothing
// Does: Tests insertAt function: one in the middle of the
//       CharArrayList, one at the last possible index, one
//       that correctly throws out_of_range exception
void testInsertAt(CharArrayList &arr) {
    cout << endl << "insert x at index 3: " << endl;
    arr.insertAt('x', 3);
    arr.print();

    //insert at last possible position
    cout << endl << "insert x at index 8: " << endl;
    arr.insertAt('x',8);
    arr.print();

    // correctly throws out_of_range exception
    // arr.insertAt('x',10);
}

// Function testInsertInOrder
// Parameters: address of a CharArrayList
// Returns: nothing
// Does: Tests insertInOrder function: one with a letter that will
//       go in middle, one that will appear at end ('z')
void testInsertInOrder(CharArrayList &arr) {
    cout << endl << "insert u in order: " << endl;
    arr.insertInOrder('u');
    arr.print();

    cout << endl << "insert z in order: " << endl;
    arr.insertInOrder('z');
    arr.print();
}

// Function testPopFromFront
// Parameters: address of a CharArrayList
// Returns: nothing
// Does: Tests popFromFront function: one normally, one with exception
void testPopFromFront(CharArrayList &arr) {
    cout << endl << "pop from front: " << endl;
    arr.popFromFront();
    arr.print();

    // correctly throws runtime_error exception
    // arr.clear();
    // arr.popFromFront();
}

// Function testPopFromBack
// Parameters: address of a CharArrayList
// Returns: nothing
// Does: Tests popFromBack function: one normally, one with exception
void testPopFromBack(CharArrayList &arr) {
    cout << endl << "pop from back: " << endl;
    arr.popFromBack();
    arr.print();

    // correctly throws runtime_error exception
    // arr.clear();
    // arr.popFromBack();
}

// Function testRemoveAt
// Parameters: address of a CharArrayList
// Returns: nothing
// Does: Tests removeAt function: one normally, one with exception
void testRemoveAt(CharArrayList &arr) {
    cout << endl << "remove element at index 2" << endl;
    arr.removeAt(2);
    arr.print();

    // throws out_of_range exception
    // arr.removeAt(8);
}

// Function testReplaceAt
// Parameters: address of a CharArrayList
// Returns: nothing
// Does: Tests replaceAt function: one normally, one with exception
void testReplaceAt(CharArrayList &arr) {
    cout << endl << "replace element at index 2 with V: " << endl;
    arr.replaceAt('V',2);
    arr.print();

    // throws out_of_range exception
    // arr.replaceAt('V',7);
}

// Function testConcatenate
// Parameters: address of a CharArrayList
// Returns: nothing
// Does: Tests concatenate function: concat empty array to an array,
//       concat array to an empty array, concat array to itself,
//       concat when it needs to expand
void testConcatenate(CharArrayList &arr, CharArrayList &arr2) {
    cout << endl << "cat array w/ empty arr: " << endl;
    arr.concatenate(&arr2);
    arr.print();

    cout << endl << "cat empty arr w/ array: " << endl;
    arr2.concatenate(&arr);
    arr.print();

    cout << endl << "cat array w/ itself: " << endl;
    arr.concatenate(&arr);
    arr.print();

    cout << endl << "do it again: " << endl;
    arr.concatenate(&arr);
    arr.print();
}

// Function testShrink
// Parameters: address of a CharArrayList
// Returns: nothing
// Does: Tests shrink function: one normally, one with exception
void testShrink(CharArrayList &arr) {
    cout << endl << "shrink it: " << endl;
    arr.shrink();
    arr.print();
}
