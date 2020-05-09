/*
 *
 *  COMP 15 HW 2 Cheshire ConCATenation - Time to Get Linked Up in Fur
 *
 *  CharLinkedList.cpp
 *  Complete CharLinkedList Class Implementation
 *  Modified By (UTLN): Devan Venkataraman
 *           On       : 02/05/2020
 *
 */

 #include <iostream>
 #include <ostream>

 #include "CharLinkedList.h"

 using namespace std;

 // default constructor
 CharLinkedList::CharLinkedList() {
     len      = 0;
     front    = nullptr;
     curr_pos = nullptr;
 }

 // constructor 2
 CharLinkedList::CharLinkedList(char e) {
     Node *node = new Node;
     node->info = e;
     node->next = nullptr;
     node->previous = nullptr;

     len = 1;
     front = node;
     curr_pos = nullptr;
 }

 // constructor 3
 CharLinkedList::CharLinkedList(char e[], int length) {
     Node *first = new Node;
     first->info = e[0];
     first->next = nullptr;
     first->previous = nullptr;
     front = first;
     len = 1;

     for (int i = 1; i < length; i++) {
         pushAtBack(e[i]);
     }
 }

 // copy constructor
 CharLinkedList::CharLinkedList(CharLinkedList &other) {
     len = other.len;
     curr_pos = nullptr;

     if (other.front == nullptr) {
         front = nullptr;
     }
     else {
         // take in the first node
         front = new Node;
         front->previous = nullptr;
         front->info = other.front->info;
         Node *orig = other.front;
         curr_pos = front;
         // take in the rest of the nodes
         while (orig->next != nullptr) {
             curr_pos->next = new Node;
             curr_pos->next->previous = curr_pos;
             curr_pos->next->info = orig->next->info;

             curr_pos = curr_pos->next;
             orig = orig->next;
         }
     }
 }

 // destructor
 CharLinkedList::~CharLinkedList() {
     clear();
 }

 // assignment operator
 CharLinkedList& CharLinkedList::operator=(CharLinkedList &rhs) {
     if (this != &rhs) {
         clear();

         len = rhs.len;
         curr_pos = nullptr;

         if (rhs.front == nullptr) {
             front = nullptr;
         }
         else {
             // take in the first node
             front = new Node;
             front->previous = nullptr;
             front->info = rhs.front->info;
             Node *orig = rhs.front;
             curr_pos = front;
             // take in the rest of the nodes
             while (orig->next != nullptr) {
                 curr_pos->next = new Node;
                 curr_pos->next->previous = curr_pos;
                 curr_pos->next->info = orig->next->info;

                 curr_pos = curr_pos->next;
                 orig = orig->next;
             }
         }
     }
     return *this;
}

 // Function print
 // Parameters: none
 // Returns: nothing
 // Does: prints the CharLinkedList
 void CharLinkedList::print() {

//--------NORMAL PRINT FUNCTION--------
    Node *node = front;
    cout << "[CharLinkedList of size " << len << " <<";

    while (node != nullptr) {
        cout << node->info;
        node = node->next;
    }

    cout << ">>]" << endl;


//--------TESTS NEXT AND PREVIOUS POINTERS--------
     // if(isEmpty()) {
     //     return;
     // }
     //
     // cout << "Testing next: " << endl;
     // curr_pos = front;
     // while (curr_pos->next != nullptr) {
     //     cout << "Element is: " << curr_pos->info << endl;
     //     curr_pos = curr_pos->next;
     // }
     // cout << "Element is: " << curr_pos->info << endl;
     //
     // cout << "Testing previous: " << endl;
     // while (curr_pos->previous != nullptr) {
     //     cout << "Element is: " << curr_pos->info << endl;
     //     curr_pos = curr_pos->previous;
     // }
     // cout << "Element is: " << curr_pos->info << endl;
 }

 // Function isEmpty
 // Parameters: none
 // Returns: boolean
 // Does: returns true if the CharLinkedList is empty, false otherwise
 bool CharLinkedList::isEmpty() {
     if (front == nullptr) {
         return true;
     }
     else {
         return false;
     }
 }

 // Function clear
 // Parameters: none
 // Returns: nothing
 // Does: clears the CharLinkedList of all characters
 void CharLinkedList::clear() {

     if (front == nullptr) {
         return;
     }

     Node *temp = front;
     // reset all nodes
     while (temp != nullptr) {
         temp = front->next;
         front->previous = nullptr;
         front->next = nullptr;
         front->info = '\0';
         delete front;

         front = temp;
         len--;
     }
 }

 // Function size
 // Parameters: none
 // Returns: integer
 // Does: Returns the number of characters in the CharLinkedList
 int CharLinkedList::size() {
     return len;
 }

 // Function first
 // Parameters: none
 // Returns: char
 // Does: Returns the first element in the CharLinkedList,
 //       throws a runtime_error if empty
 char CharLinkedList::first() {
     if (isEmpty()) {
         throw runtime_error("cannot get first of empty doubly-linked list");
     }
     else {
         return front->info;
     }
 }

 // Function last
 // Parameters: none
 // Returns: char
 // Does: Returns the last element in the CharLinkedList,
 //       throws a runtime_error if empty
 char CharLinkedList::last() {
     if (isEmpty()) {
         throw runtime_error("cannot get last of empty doubly-linked list");
     }
     else {
         curr_pos = front;
         // locates the last element, sets curr_pos = to it
         while (curr_pos->next != nullptr) {
             curr_pos = curr_pos->next;
         }
         return curr_pos->info;
     }
 }

 // Function elementAt
 // Parameters: integer
 // Returns: char
 // Does: returns the element at the given index, throws
 //       out_of_range exception if index is out of range
 char CharLinkedList::elementAt(int index) {
     string error = "index (" + to_string(index) + ") not in range [0.."
                    + to_string(len) + ")";
     if (index >= len) {
         throw out_of_range(error);
     }

     curr_pos = front;
     for (int i = 0; i < index; i++) {
         curr_pos = curr_pos->next;
     }
     return curr_pos->info;
 }

 // Function pushAtBack
 // Parameters: char
 // Returns: nothing
 // Does: adds an element to the end of the CharLinkedList
 void CharLinkedList::pushAtBack(char element) {
     if(front == nullptr) {
         pushAtFront(element);
         return;
     }

     Node *node = new Node;
     node->info = element;
     node->next = nullptr;

     curr_pos = front;
     // locates the last element, sets curr_pos = to it
     while (curr_pos->next != nullptr) {
         curr_pos = curr_pos->next;
     }

     node->previous = curr_pos;
     curr_pos->next = node;
     len++;
 }

 // Function pushAtFront
 // Parameters: none
 // Returns: char
 // Does: adds an element to the front of the CharLinkedList
 void CharLinkedList::pushAtFront(char element) {
     Node *node = new Node;

     // if it's not an empty array
     if (front != nullptr) {
         front->previous = node;
         node->next = front;
     }
     // if it is an empty array
     else {
         node->next = nullptr;
         node->previous = nullptr;
     }

     node->info = element;
     front = node;
     len++;
 }

 // Function insertAt
 // Parameters: char, int
 // Returns: nothing
 // Does: adds an element to the front of the CharLinkedList,
 //       throws out of range error if index is out of range
 void CharLinkedList::insertAt(char element, int index) {
     string error = "index (" + to_string(index) + ") not in range [0.."
                    + to_string(len) + "]";
     if (index > len) {
        throw out_of_range(error);
     }
     // if inserting last, just push at back
     else if (index == len) {
         pushAtBack(element);
         return;
     }
     // if inserting first, just push at front
     else if (index == 0) {
         pushAtFront(element);
         return;
     }

     Node *node = new Node;
     node->info = element;

     // locate index in list
     curr_pos = front;
     for (int i = 0; i < index; i++) {
         curr_pos = curr_pos->next;
     }

     // update pointers
     node->next = curr_pos;
     node->previous = curr_pos->previous;
     curr_pos->previous->next = node;
     curr_pos->previous = node;

     len++;
 }

 // Function insertInOrder
 // Parameters: char
 // Returns: nothing
 // Does: Inserts an element in alphabetical order
 void CharLinkedList::insertInOrder(char element) {
     if (isEmpty()) {
         insertAt(element, 0);
         return;
     }

     int index = 0;
     curr_pos = front;
     while (curr_pos != nullptr) {
         // check alpha location
         if (curr_pos->info > element) {
             insertAt(element, index);
             return;
         }
         // otherwise, insert it at the end
         else if (curr_pos->next == nullptr) {
             insertAt(element, index + 1);
             return;
         }
         index++;
         curr_pos = curr_pos->next;
     }
 }

 // Function popFromFront
 // Parameters: none
 // Returns: void
 // Does: removes the first element of the CharLinkedList,
 //       throws runtime_error if the CharLinkedList is empty
 void CharLinkedList::popFromFront() {
     if (isEmpty()) {
         throw runtime_error("cannot pop from empty doubly-linked list");
     }
     else {
         removeAt(0);
     }
 }

 // Function popFromBack
 // Parameters: none
 // Returns: nothing
 // Does: removes the last element of the CharLinkedList,
 //       throws runtime_error if the CharLinkedList is empty
 void CharLinkedList::popFromBack() {
     if (isEmpty()) {
         throw runtime_error("cannot pop from empty doubly-linked list");
     }
     else {
         removeAt(len-1);
     }
 }

 // Function removeAt
 // Parameters: int
 // Returns: nothing
 // Does: removes element at the desired index of the CharLinkedList,
 //       throws out_of_range error if index is out of range
 void CharLinkedList::removeAt(int index) {

     string error = "index (" + to_string(index) + ") not in range [0.."
                    + to_string(len) + ")";
     if (index >= len) {
         throw out_of_range(error);
     }

     // locate the element to be removed
     curr_pos = front;
     for (int i = 0; i < index; i++) {
         curr_pos = curr_pos->next;
     }

     // if this is the only element
     if (len == 1) {
         front = nullptr;
     }
     // if this is the first but not only element
     else if (curr_pos == front) {
         front = curr_pos->next;
         curr_pos->next->previous = nullptr;
     }
     // if this is the last but not only element
     else if (curr_pos->next == nullptr) {
        curr_pos->previous->next = nullptr;
     }
     // it's somewhere in the middle
     else {
         curr_pos->previous->next = curr_pos->next;
         curr_pos->next->previous = curr_pos->previous;
     }

     delete curr_pos;
     len--;
 }

 // Function replaceAt
 // Parameters: char, int
 // Returns: nothing
 // Does: replaces the element of the CharLinkedList at the desired index,
 //       throws out_of_range error if index is out of range
 void CharLinkedList::replaceAt(char element, int index) {
     string error = "index (" + to_string(index) + ") not in range [0.."
                    + to_string(len) + ")";
     if (index >= len) {
         throw out_of_range(error);
     }
     Node *node = new Node;
     node->info = element;
     // locate the element to be replaced
     curr_pos = front;
     for (int i = 0; i < index; i++) {
         curr_pos = curr_pos->next;
     }
     // if this is the only element
     if (len == 1) {
         front = node;
     }
     // if this is the first but not only element
     else if (curr_pos == front) {
         front = node;
         node->previous = nullptr;
         node->next = curr_pos->next;
         curr_pos->next->previous = node;
     }
     // if this is the last but not only element
     else if (curr_pos->next == nullptr) {
         node->previous = curr_pos->previous;
         node->next = nullptr;
         curr_pos->previous->next = node;
     }
     // it's somewhere in the middle
     else {
         curr_pos->previous->next = node;
         curr_pos->next->previous = node;
         node->previous = curr_pos->previous;
         node->next = curr_pos->next;
     }
     delete curr_pos;
 }

 // Function concatenate
 // Parameters: pointer to a CharLinkedList
 // Returns: nothing
 // Does: concatenates the array pointed to to the original array
 void CharLinkedList::concatenate(CharLinkedList *list_to_add) {
     for (int i = 0; i < list_to_add->len; i++) {
         pushAtBack(list_to_add->elementAt(i));
     }
 }

 // Function shrink
 // Parameters: none
 // Returns: nothing
 // Does: shrink the capacity of the array to the minimize size /
 //       memory it requires
 void CharLinkedList::shrink() {
     return;
 }

 // Function find
 // Parameters: char element
 // Returns: boolean value
 // Does: It will return "true" if the CharLinkedList contains
 //       the specified element and "false" if it does not.
 bool CharLinkedList::find(char element) {
     return scanList(front, element);
 }

//-----------BEGINNING OF PRIVATE FUNCTIONS-----------

// Function scanList
// Parameters: pointer to a node, char element
// Returns: boolean value
// Does: Recursive function, returns true if element found,
//       false if at end of list, otherwise recurses w/ next node
 bool CharLinkedList::scanList(Node *node, char element) {
     if (node->info == element) {
         return true;
     }
     else if (node->next == nullptr) {
         return false;
     }
     else {
         return (scanList(node->next, element));
     }
 }
