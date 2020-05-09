/*
 *      CircularBuffer.cpp
 *      PartyPlaylist
 *      Comp 15 Lab 3
 *
 *      2020-02-04 Created by Devan Venkataraman
 */

#include <iostream>
#include <stdexcept>

#include "CircularBuffer.h"


using namespace std;


/*
 * Return the index of the next element in the buffer.
 * Wraps around!
 */

int CircularBuffer::nextIndex(int index)
{
    return (index + 1) % capacity;
}


/* Default Constructor */
CircularBuffer::CircularBuffer()
{
        init(INIT_CAPACITY);
}

/*
 * Overloaded Constructor for a sequence with a hint for an initial
 * capacity.
 */
CircularBuffer::CircularBuffer(int initialCapacity)
{
        init(initialCapacity);
}

/*
 * Initialize a new, empty CircularBuffer with an initial capacity.
 */
void CircularBuffer::init(int initialCapacity)
{
        capacity      = initialCapacity;
        bufferArray = new ElementType[capacity];
        currentSize   = 0;
        front         = 0;
        back          = 0;
}

/*
 * Destructor:  recycles the dynamically allocated array containing
 * the data.
 */
CircularBuffer::~CircularBuffer()
{
        delete [] bufferArray;
}

/*
 *  Add given element to the back of the list
 */
void CircularBuffer::addAtBack(ElementType elem)
{
        if (currentSize == capacity) {
                expand();
        }
        bufferArray[back] = elem;
        currentSize++;
        back                = nextIndex(back);
}

/*
 *  Add given element to the front of the list
 */
void CircularBuffer::addAtFront(ElementType elem)
{
        if (currentSize == capacity) {
            expand();
        }


        string temp = bufferArray[currentSize - 1];
        cout << temp << endl;

        for (int i = currentSize; i >= 0; i--) {
            bufferArray[i+1] = bufferArray[i];
        }

        bufferArray[front] = elem;
        bufferArray[currentSize] = temp;
        currentSize++;
}

/*
 * Remove the element at the back of the list
 * and return it.
 */
ElementType CircularBuffer::removeFromBack()
{
    if(currentSize == 0)
        return NULL;

    back = back - 1;
    if(back < 0)
        back = capacity - front - 1;

    currentSize --;

    return bufferArray[back];
}

/*
 * Remove the element at the front of the list
 * and return it.
 */
ElementType CircularBuffer::removeFromFront()
{
    if(currentSize == 0) {
        return NULL;
    }

    front--;
    if(back < 0) {
        back = capacity - front -1;
    }

    return bufferArray[front];
}

/*
 * Expand the capacity of the array by a factor of 2.
 */
void CircularBuffer::expand()
{
    capacity = capacity*2 + 2;
}

/*
 * Print the contents of the CircularBuffer, one element per line.
 */
void CircularBuffer::printBuffer()
{
        int currIndex = front;
        for (int i = 0; i < currentSize; i++) {
                cout << bufferArray[currIndex] << endl;
                currIndex = nextIndex(currIndex);
        }
}
