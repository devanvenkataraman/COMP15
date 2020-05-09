/*
 *
 *  COMP 15 HW 2 Cheshire ConCATenation - Time to Get Linked Up in Fur
 *
 *  testCharLinkedList.cpp
 *  Testing File for the sequence CharLinkedList class
 *
 *  Written by: Devan Venkataraman
 *          on: 02.05.20
 */

#include <iostream>
#include "CharLinkedList.h"
using namespace std;

void testGroupOne(CharLinkedList &list1, CharLinkedList &list2, CharLinkedList &list3);
void testGroupTwo(CharLinkedList &list1, CharLinkedList &list2, CharLinkedList &list3);
void testIsEmpty(CharLinkedList &list);
void testClear(CharLinkedList &list);
void testPrint(CharLinkedList &list);
void testFirst(CharLinkedList &list);
void testLast(CharLinkedList &list);
void testElementAt(CharLinkedList &list);
void testPushAtBack(CharLinkedList &list);
void testPushAtFront(CharLinkedList &list);
void testInsertAt(CharLinkedList &list);
void testEmptyInsertAt(CharLinkedList &list);
void testInsertInOrder(CharLinkedList &list);
void testPopFromFront(CharLinkedList &list);
void testPopFromBack(CharLinkedList &list);
void testRemoveAt(CharLinkedList &list);
void testReplaceAt(CharLinkedList &list);
void testConcatenate(CharLinkedList &list, CharLinkedList &list2);
void testShrink(CharLinkedList &list);
void testFind(CharLinkedList &list);

int main()
{
    // test default constructor
    CharLinkedList list1;
    // test constructor 2
    CharLinkedList list2('d');
    // test constructor 3
    char array3[5] = {'d', 'e', 'v', 'a', 'n'};
    CharLinkedList list3(array3, 5);

    char array4[2] = {'h', 'i'};
    CharLinkedList list4(array4, 2);

    // test copy constructor
    // CharLinkedList list5 = list3;
    // cout << "test copy constructor:" << endl;
    // cout << "List 5 (copy) is:" << endl;
    // list5.print();
    // cout << "List 3 is:" << endl;
    // list3.print();
    //
    // // test assignment operator
    // list2 = list3;
    // list2.print();

    // test the first group of functions
    testGroupOne(list1, list2, list3);
    // test the second group of functions
    testGroupTwo(list1, list2, list3);
}

// Function testGroupOne
// Parameters: Three CharLinkedList references
// Returns: nothing
// Does: Tests about half of the required functions
void testGroupOne(CharLinkedList &list1, CharLinkedList &list2, CharLinkedList &list3) {
    testIsEmpty(list1);
    testIsEmpty(list2);
    testPrint(list3);

    testFirst(list3);
    testLast(list3);
    testElementAt(list3);
    // test empty list pushAtBack, but make it empty again
    testPushAtBack(list1);
    testClear(list1);
    // test standard pushAtBack
    testPushAtBack(list3);
    testPushAtFront(list3);
    // test empty list pushAtFront, but make it empty again
    testPushAtFront(list1);
    testClear(list1);
}

// Function testGroupTwo
// Parameters: Two CharLinkedList references
// Returns: nothing
// Does: Tests the remaining required functions
void testGroupTwo(CharLinkedList &list1, CharLinkedList &list2, CharLinkedList &list3) {
    testInsertAt(list3);
    testEmptyInsertAt(list1);
    testInsertInOrder(list3);
    testPopFromFront(list3);
    // pop from single char list, but replace the letter after
    testPopFromFront(list2);
    testPushAtBack(list2);

    testPopFromBack(list3);
    // pop from single char list, but replace the letter after
    testPopFromBack(list2);
    testPushAtBack(list2);

    testRemoveAt(list3);
    testReplaceAt(list3);
    testConcatenate(list1, list3);
    testFind(list3);
    testShrink(list3);
    testClear(list3);
}

// Function testIsEmpty
// Parameters: address of a CharLinkedList
// Returns: nothing
// Does: Tests isEmpty function
void testIsEmpty(CharLinkedList &list) {
    bool result = list.isEmpty();
    list.print();
    cout << "The result of isEmpty is: " << result << endl;
}

// Function testClear
// Parameters: address of a CharLinkedList
// Returns: nothing
// Does: Tests clear function
void testClear(CharLinkedList &list) {
    cout << endl << "clear it: " << endl;
    list.clear();
    list.print();
}

// Function testPrint
// Parameters: address of a CharLinkedList
// Returns: nothing
// Does: Tests print function
void testPrint(CharLinkedList &list) {
    cout << endl << "print it: " << endl;
    list.print();
}

// Function testFirst
// Parameters: address of a CharLinkedList
// Returns: nothing
// Does: Tests first function: one normally, one with exception
void testFirst(CharLinkedList &list) {
    cout << endl << "first char is: " << endl;
    cout << list.first() << endl;

    // correctly throws runtime_error exception
    // list.clear();
    // list.first();
}

// Function testFirst
// Parameters: address of a CharLinkedList
// Returns: nothing
// Does: Tests last function: one normally, one with exception
void testLast(CharLinkedList &list) {
    cout << endl << "last char is: " << endl;
    cout << list.last() << endl;

    // correctly throws runtime_error exception
    // list.clear();
    // list.last();
}

// Function testElementAt
// Parameters: address of a CharLinkedList
// Returns: nothing
// Does: Tests isEmpty function: one normally, one with its exception
void testElementAt(CharLinkedList &list) {
    cout << endl << "element at index 4 is: " << endl;
    cout << list.elementAt(4) << endl;

    // correctly throws out_of_range exception
    // list.elementAt(5);
}

// Function testPushAtBack
// Parameters: address of a CharLinkedList
// Returns: nothing
// Does: Tests pushAtBack function
void testPushAtBack(CharLinkedList &list) {
    cout << endl << "push s at back: " << endl;
    list.pushAtBack('s');
    list.print();
}

// Function testPushAtFront
// Parameters: address of a CharLinkedList
// Returns: nothing
// Does: Tests pushAtFront function
void testPushAtFront(CharLinkedList &list) {
    cout << endl << "push a at front: " << endl;
    list.pushAtFront('a');
    list.print();
}

// Function insertAt
// Parameters: address of a CharLinkedList
// Returns: nothing
// Does: Tests insertAt function: one in the middle of the
//       CharLinkedList, one at the last possible index, one
//       that correctly throws out_of_range exception
void testInsertAt(CharLinkedList &list) {
    cout << endl << "test normally: insert x at index 3: " << endl;
    list.insertAt('x', 3);
    list.print();

    //insert at last possible position
    cout << endl << "test end: insert x at index 8: " << endl;
    list.insertAt('x', 8);
    list.print();

    cout << endl << "test beginning: insert g at index 0: " << endl;
    list.insertAt('g', 0);
    list.print();

    // correctly throws out_of_range exception
    // list.insertAt('x',15);
}

// Function testInsertInOrder
// Parameters: address of a CharLinkedList
// Returns: nothing
// Does: Tests insertInOrder function: one with a letter that will
//       go in middle, one that will appear at end ('z')
void testInsertInOrder(CharLinkedList &list) {
    cout << endl << "insert u in order: " << endl;
    list.insertInOrder('u');
    list.print();

    cout << endl << "insert z in order: " << endl;
    list.insertInOrder('z');
    list.print();
}

// Function testPopFromFront
// Parameters: address of a CharLinkedList
// Returns: nothing
// Does: Tests popFromFront function: one normally, one with exception
void testPopFromFront(CharLinkedList &list) {
    cout << endl << "pop from front: " << endl;
    list.popFromFront();
    list.print();

    // correctly throws runtime_error exception
    // list.clear();
    // list.popFromFront();
}

// Function testPopFromBack
// Parameters: address of a CharLinkedList
// Returns: nothing
// Does: Tests popFromBack function: one normally, one with exception
void testPopFromBack(CharLinkedList &list) {
    cout << endl << "pop from back: " << endl;
    list.popFromBack();
    list.print();

    // correctly throws runtime_error exception
    // list.clear();
    // list.popFromBack();
}

// Function testRemoveAt
// Parameters: address of a CharLinkedList
// Returns: nothing
// Does: Tests removeAt function: one normally, one with exception
//       Note: both pop functions already test removing from ends
//             and removing single element lists
void testRemoveAt(CharLinkedList &list) {
    cout << endl << "remove element at index 2" << endl;
    list.removeAt(2);
    list.print();

    // throws out_of_range exception
    // list.removeAt(20);
}

// Function testReplaceAt
// Parameters: address of a CharLinkedList
// Returns: nothing
// Does: Tests replaceAt function: one normally, one with exception
void testReplaceAt(CharLinkedList &list) {
    cout << endl << "replace element at index 5 with V: " << endl;
    list.replaceAt('V', 5);
    list.print();

    cout << endl << "test front: replace element at index 0 with D: " << endl;
    list.replaceAt('D', 0);
    list.print();

    cout << endl << "test back: replace element at index 8 with X: " << endl;
    list.replaceAt('X', 8);
    list.print();

    // throws out_of_range exception
    // list.replaceAt('V', 20);
}

// Function testConcatenate
// Parameters: address of a CharLinkedList
// Returns: nothing
// Does: Tests concatenate function: concat empty array to an array,
//       concat array to an empty array, concat array to itself,
//       concat when it needs to expand
void testConcatenate(CharLinkedList &list1, CharLinkedList &list3) {
    cout << endl << "cat empty list w/ normal list: " << endl;
    list1.concatenate(&list3);
    list1.print();
    list1.clear();

    cout << endl << "cat normal list w/ empty list: " << endl;
    list3.concatenate(&list1);
    list3.print();
}

// Function testShrink
// Parameters: address of a CharLinkedList
// Returns: nothing
// Does: Tests shrink function: one normally, one with exception
void testShrink(CharLinkedList &list) {
    cout << endl << "shrink it: " << endl;
    list.shrink();
    list.print();
}

// Function testFind
// Parameters: address of a CharLinkedList
// Returns: nothing
// Does: Tests find function: one with true result, one false
void testFind(CharLinkedList &list) {
    cout << endl << "result of finding the letter 'f': ";
    cout << list.find('f') << endl;

    cout << "result of finding the letter 'n': ";
    cout << list.find('n') << endl;
}

// Function testEmptyInsertAt
// Parameters: address of a CharLinkedList
// Returns: nothing
// Does: tests insert function for an empty array list
void testEmptyInsertAt(CharLinkedList &list) {
    cout << endl << "test with empty array: insert x at index 0: " << endl;
    list.insertAt('x', 0);
    list.print();
    list.clear();
}
