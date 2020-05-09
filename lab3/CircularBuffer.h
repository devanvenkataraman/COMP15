/*
 *      CircularBuffer.h
 *      PartyPlaylist
 *      Comp 15 Lab 3
 *
 *      A class that represents an ordered sequence of elements.  This
 *      one is for strings.
 *
 *      2020-02-04 Created by Devan Venkataraman
 */


#ifndef CIRCULAR_BUFFER_H
#define CIRCULAR_BUFFER_H

#include "ElementType.h"

class CircularBuffer
{
public:
        CircularBuffer();
        CircularBuffer(int givenCapcity);
        ~CircularBuffer();

        void        addAtBack (ElementType elem);
        void        addAtFront(ElementType elem);
        ElementType removeFromBack();
        ElementType removeFromFront();

        void        printBuffer();

private:
        static const int INIT_CAPACITY = 5;

        ElementType     *bufferArray;
        int              currentSize;
        int              capacity;
        int              front;
        int              back;

        int  nextIndex(int index);
        void expand();
        void init(int givenCapacity);
};

#endif
