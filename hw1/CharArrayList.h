/*
 *
 *  COMP 15 HW 1 Cheshire ConCATenation - no strings attached
 *
 *  CharArrayList.h
 *
 *  Complete Array List Class Declaration
 *
 *  Modified By Devan Venkataraman:
 *           On 01.30.20          :
 *
 */
 #include <string>

 #ifndef CHARARRAYLIST_H_
 #define CHARARRAYLIST_H_

 class CharArrayList
 {
     public:
         CharArrayList();
         CharArrayList(char e);
         CharArrayList(char e[], int length);
         CharArrayList(CharArrayList &other);
         ~CharArrayList();
         CharArrayList& operator = (CharArrayList &rhs);
         bool isEmpty();
         void clear();
         int size();
         char first();
         char last();
         char elementAt(int index);
         void print();
         void pushAtBack(char element);
         void pushAtFront(char element);
         void insertAt(char element, int index);
         void insertInOrder(char element);
         void popFromFront();
         void popFromBack();
         void removeAt(int index);
         void replaceAt(char element, int index);
         void concatenate(CharArrayList *array_to_add);
         void shrink();

     private:
         char *arr;
         int numChars;
         int capacity;

         void resize(int newSize);
         void expand();
         char getChar(int index);
 };

 #endif
