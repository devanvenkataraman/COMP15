/*
 * Implementation of ArrayList class
 */
#include <iostream>

#include "ArrayList.h"

using namespace std;

static const int DEFAULT_SIZE = 5;

// Default Constructor
ArrayList::ArrayList()
{
	arr      = new string[DEFAULT_SIZE];
	numItems = 0;
	capacity = DEFAULT_SIZE;
}

// Destructor
ArrayList::~ArrayList()
{
    delete[] arr;
}

// Function size
// Parameters: none
// Returns: number it items currently in list (not capacity)
int ArrayList::size()
{
	return numItems;
}

// Function insert
// Parameters: string item - value to insert into array
// Returns: nothing
// Does: Adds given item to list
void ArrayList::insert(string item)
{
	if (numItems == capacity) {
		expand();
	}
	arr[numItems] = item;
	numItems++;
}

// Function remove
// Parameters: string item - value to remove from array
// Returns: bool - whether the item was removed or not
// Does: Removes item if present
bool ArrayList::remove(string item)
{
    if (numItems < capacity/2) {
		shrink();
	}

    int index = find(item);
	if (index >= 0)
		arr[index] = "";
	else
		return false;

	shift();
	numItems--;

	return true;
}

// Function find
// Parameters: string item - value to search for in array
// Returns: int - index of item in array, -1 if item not found
int ArrayList::find(string item)
{
	for (int i = 0; i < numItems; i++) {
		if (arr[i] == item)
			return i;
	}
	return -1;
}

// Function shift
// Parameters: none
// Returns: nothing
// Does: Shifts elements to the left if there is an empty space
void ArrayList::shift()
{
	for (int i = 1; i < numItems; i++) {
		if (arr[i - 1] == ""){
			arr[i - 1] = arr[i];
			arr[i] = "";
		}
	}
}

// Function print
// Parameters: ostream & - where to print
// Returns: nothing
// Does: Prints out each item on the list
void ArrayList::print(ostream &out)
{
	for (int i = 0; i < numItems; i++) {
		out << " - " << arr[i] << endl;
	}
}

// Function expand
// Parameters: none
// Returns: nothing
// Does: Expands the array by a factor of two
void ArrayList::expand()
{
    resize(capacity*2);
}

// Function shrink
// Parameters: none
// Returns: nothing
// Does: Shrinks the array by a factor of two
void ArrayList::shrink()
{
    resize(capacity/2);
}

// Function resize
// Parameters: int newSize - size of new array
// Returns: nothing
// Does: Updates the capacity of the array to the given size
void ArrayList::resize(int newSize)
{
    capacity = newSize;
	string *new_arr = new string[capacity];

	for (int i = 0; i < numItems; i++) {
		new_arr[i] = arr[i];
	}

    delete[] arr;
	arr = new_arr;
}
