/*
 *
 *  COMP 15 HW 1 Cheshire ConCATenation - no strings attached
 *
 *  CharArrayList.cpp
 *
 *  Complete CharArrayList Class Implementation
 *
 *  Modified By Devan Venkataraman:
 *           On 01.30.20          :
 *
 */
#include <iostream>
#include <string>

#include "CharArrayList.h"

using namespace std;

// default constructor
CharArrayList::CharArrayList() {
    numChars = 0;
    capacity = 0;
    arr = new char[capacity];
}

// constructor 2
CharArrayList::CharArrayList(char e) {
    capacity = 1;
    numChars = 1;
    arr = new char[capacity];
    arr[0] = e;
}

// constructor 3
CharArrayList::CharArrayList(char e[], int length) {
    capacity = length;
    numChars = length;
    arr = new char[capacity];
    // fill the array list with the characters
    for (int i = 0; i < length; i++) {
        arr[i] = e[i];
    }
}

// copy constructor
CharArrayList::CharArrayList(CharArrayList &other) {
    numChars = other.numChars;
    capacity = other.capacity;
    arr     = new char[numChars];

    // copy the characters over
    for (int i = 0; i < numChars; ++i) {
        arr[i] = other.arr[i];
    }
}

// destructor
CharArrayList::~CharArrayList() {
    delete[] arr;
    arr = nullptr;
    numChars = capacity = -1;
}

// assignment operator
CharArrayList& CharArrayList::operator=(CharArrayList &rhs) {
    if (this != &rhs) {   // only assign if not self-assignment
        delete [] arr;  // recycle before overwriting var
        // Now safe to copy RHS into LHS
        numChars = rhs.numChars;
        capacity = rhs.capacity;
        arr = new char[numChars];

        for (int i = 0; i < numChars; ++i) {
            arr[i] = rhs.arr[i];
        }
    }
    return *this;
}

// Function print
// Parameters: none
// Returns: nothing
// Does: prints the CharArrayList
void CharArrayList::print() {
    cout << "[CharArrayList of size " << numChars << " <<";
    for (int i = 0; i < numChars; i++) {
        cout << arr[i];
    }
    cout << ">>]" << endl;
}

// Function isEmpty
// Parameters: none
// Returns: boolean
// Does: returns true if the CharArrayList is empty, false otherwise
bool CharArrayList::isEmpty() {
    if (numChars == 0) {
        return true;
    }
    else {
        return false;
    }
}

// Function clear
// Parameters: none
// Returns: nothing
// Does: clears the CharArrayList of all characters
void CharArrayList::clear() {
    for (int i = 0; i < numChars; i++) {
        arr[i] = 0;
    }
    numChars = 0;
}

// Function size
// Parameters: none
// Returns: integer
// Does: Returns the number of characters in the CharArrayList
int CharArrayList::size() {
    if (isEmpty()) {
        return 0;
    }
    else {
        return numChars;
    }
}

// Function first
// Parameters: none
// Returns: char
// Does: Returns the first element in the CharArrayList,
//       throws a runtime_error if empty
char CharArrayList::first() {
    if (isEmpty()) {
        throw runtime_error("cannot get first of empty ArrayList");
    }
    else {
        return arr[0];
    }
}

// Function last
// Parameters: none
// Returns: char
// Does: Returns the last element in the CharArrayList,
//       throws a runtime_error if empty
char CharArrayList::last() {
    if (isEmpty()) {
        throw runtime_error("cannot get last of empty ArrayList");
    }
    else {
        return arr[numChars-1];
    }
}

// Function elementAt
// Parameters: integer
// Returns: char
// Does: returns the element at the given index, throws
//       out_of_range exception if index is out of range
char CharArrayList::elementAt(int index) {
    string error = "index (" + to_string(index) + ") not in range [0.."
                   + to_string(numChars) + ")";
    if (index >= numChars) {
        throw out_of_range(error);
    }
    else {
        return arr[index];
    }
}

// Function pushAtBack
// Parameters: char
// Returns: nothing
// Does: adds an element to the end of the CharArrayList
void CharArrayList::pushAtBack(char element) {
    insertAt(element, numChars);
}

// Function pushAtFront
// Parameters: none
// Returns: char
// Does: adds an element to the front of the CharArrayList
void CharArrayList::pushAtFront(char element) {
    insertAt(element, 0);
}

// Function insertAt
// Parameters: char, int
// Returns: nothing
// Does: adds an element to the front of the CharArrayList,
//       throws out of range error if index is out of range
void CharArrayList::insertAt(char element, int index) {
    string error = "index (" + to_string(index) + ") not in range [0.."
                   + to_string(numChars) + "]";
    if (numChars == capacity) {
        expand();
    }
    if (index > numChars) {
        throw out_of_range(error);
    }
    // shift the characters after rightward
    for (int i = numChars-1; i >= index; i--) {
        arr[i+1] = arr[i];
    }
    arr[index] = element;
    numChars +=1;
}

// Function insertInOrder
// Parameters: char
// Returns: nothing
// Does: Inserts an element in alphabetical order
void CharArrayList::insertInOrder(char element) {
    if (numChars == capacity) {
        expand();
    }
    //insert alphabetically
    for (int i = 0; i < numChars; i++) {
        if (element < arr[i]) {
            insertAt(element, i);
            return;
        }
    }
    // in the case that the element is alphabetically
    // last in the array
    insertAt(element, numChars);
    return;
}

// Function popFromFront
// Parameters: none
// Returns: void
// Does: removes the first element of the CharArrayList,
//       throws runtime_error if the CharArrayList is empty
void CharArrayList::popFromFront() {
    if (isEmpty()) {
        throw runtime_error("cannot pop from empty ArrayList");
    }
    else {
        removeAt(0);
    }
}

// Function popFromBack
// Parameters: none
// Returns: nothing
// Does: removes the last element of the CharArrayList,
//       throws runtime_error if the CharArrayList is empty
void CharArrayList::popFromBack() {
    if (isEmpty()) {
        throw runtime_error("cannot pop from empty ArrayList");
    }
    else {
        removeAt(numChars-1);
    }
}

// Function removeAt
// Parameters: int
// Returns: nothing
// Does: removes element at the desired index of the CharArrayList,
//       throws out_of_range error if index is out of range
void CharArrayList::removeAt(int index) {
    string error = "index (" + to_string(index) + ") not in range [0.."
                   + to_string(numChars) + ")";
    if (index >= numChars) {
        throw out_of_range(error);
    }
    // shift the elements leftward
    for (int i = index; i < numChars-1; i++) {
        arr[i] = arr[i+1];
    }
    // delete the repeated last element and decrement size
    arr[numChars-1] = 0;
    numChars--;
}

// Function replaceAt
// Parameters: char, int
// Returns: nothing
// Does: replaces the element of the CharArrayList at the desired index,
//       throws out_of_range error if index is out of range
void CharArrayList::replaceAt(char element, int index) {
    string error = "index (" + to_string(index) + ") not in range [0.."
                   + to_string(numChars) + ")";
    if (index >= numChars) {
        throw out_of_range(error);
    }
    arr[index] = element;
}

// Function concatenate
// Parameters: pointer to a CharArrayList
// Returns: nothing
// Does: concatenates the array pointed to to the original array
void CharArrayList::concatenate(CharArrayList *array_to_add) {
    int array_to_add_chars = array_to_add->numChars;
    while (capacity < numChars + array_to_add_chars) {
        expand();
    }
    // cycle through the array to be added and add elements
    // to the end of the original array
    for (int i = 0; i < array_to_add_chars; i++) {
        arr[numChars + i] = array_to_add->getChar(i);
    }
    // size has increased by the size of the added array
    numChars += array_to_add_chars;
}

// Function shrink
// Parameters: none
// Returns: nothing
// Does: shrink the capacity of the array to the minimize size /
//       memory it requires
void CharArrayList::shrink() {
    capacity = numChars;
	char *new_arr = new char[capacity];
    // copy elements over to the new array
	for (int i = 0; i < numChars; i++) {
		new_arr[i] = arr[i];
	}

    delete[] arr;
	arr = new_arr;
}

// ------- START OF PRIVATE FUNCTIONS -------

// Function resize
// Parameters: int
// Returns: nothing
// Does: resizes the array to the size of the parameter
void CharArrayList::resize(int newSize)
{
    capacity = newSize;
	char *new_arr = new char[capacity];
    // copy elements over to the new array
	for (int i = 0; i < numChars; i++) {
		new_arr[i] = arr[i];
	}

    delete[] arr;
	arr = new_arr;
}

// Function expand
// Parameters: none
// Returns: nothing
// Does: expands the array capacity by a factor of 2, + 2
void CharArrayList::expand() {
    resize(capacity*2+2);
}

// Function getChar
// Parameters: int
// Returns: nothing
// Does: getter that provides the element at the index of the parameter
char CharArrayList::getChar(int index) {
    return arr[index];
}
