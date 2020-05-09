
/*
 *
 *  COMP 15 HW 2 Cheshire ConCATenation - Time to Get Linked Up in Fur
 *
 *  CharLinkedList.cpp
 *  Complete CharLinkedList Class Header and Declaration
 *  Modified By (UTLN): Devan Venkataraman
 *           On       : 02/05/2020
 *
 */

 #ifndef LINKED_LIST_H_
 #define LINKED_LIST_H_

 #include <ostream>

 class CharLinkedList
 {
 public:
     CharLinkedList();
     CharLinkedList(char e);
     CharLinkedList(char e[], int length);
     CharLinkedList(CharLinkedList &other);
     ~CharLinkedList();
     CharLinkedList& operator=(CharLinkedList &rhs);
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
     void concatenate(CharLinkedList *list_to_add);
     void shrink();
     bool find(char element);

 private:
     struct Node {
             char  info;
             Node   *next;
             Node *previous;
     };

     int   len;
     Node *front;
     Node *curr_pos;

     bool scanList(Node *node, char element);

 };

 #endif
