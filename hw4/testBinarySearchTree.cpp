/*
 * testBinarySearchTree.cpp
 *
 *  Created on: March 10, 2020
 *      Author: Devan Venkataraman
 *
 *  Main driver for testing the BinarySearchTree class
 */

#include <iostream>

#include "BinarySearchTree.h"

using namespace std;

void print_tree_details(BinarySearchTree &bst);
void test_insert(BinarySearchTree &bst0,
                 BinarySearchTree &bst1,
                 BinarySearchTree &bst2);
void test_contains(BinarySearchTree &bst0,
                   BinarySearchTree &bst1,
                   BinarySearchTree &bst2);
void test_remove(BinarySearchTree &bst0,
                 BinarySearchTree &bst1,
                 BinarySearchTree &bst2);

int main()
{
        // bst0 is an empty tree
        BinarySearchTree bst0;

        BinarySearchTree bst1;
        bst1.insert(4);

        BinarySearchTree bst2;
        int values[]  = {6, 9, -4, 0, 8, 2, 18, 3, 2, -2, 1, 5, 13, 14};
        int numValues = sizeof(values) / sizeof(int);
        for (int i = 0; i < numValues; i++) {
                bst2.insert(values[i]);
        }

        // test copy constructor
        BinarySearchTree bst_copy_constructor = bst2;
        bst_copy_constructor.print_tree();

        // test assignment operator
        BinarySearchTree bst_copy_1;
        bst_copy_1 = bst2;
        bst_copy_1.print_tree();

        test_insert(bst0, bst1, bst2);
        test_contains(bst0, bst1, bst2);
        test_remove(bst0, bst1, bst2);

        return 0;
}

// Function test_initial_print
// Parameters: 3 pointers to Nodes
// Returns: void
// Does: tests that the insert worked correctly
void test_insert(BinarySearchTree &bst0,
                 BinarySearchTree &bst1,
                 BinarySearchTree &bst2) {

        cout << "Print empty tree: " << endl;
        print_tree_details(bst0);

        cout << "Print tree with 1 node: " << endl;
        print_tree_details(bst1);

        cout << "Original tree "
             << "(asterisks denote a count of more than 1):\n";
        print_tree_details(bst2);
}

// Function test_contains
// Parameters: 3 pointers to Nodes
// Returns: void
// Does: tests contains function
void test_contains(BinarySearchTree &bst0,
                   BinarySearchTree &bst1,
                   BinarySearchTree &bst2) {
        cout << "Test contains with empty tree: " << endl;
        cout << "Tree "
             << (bst0.contains(3) ? "contains " : "does not contain ")
             << "the value " << 3 << "\n\n";

        cout << "Test contains with 1 node tree: " << endl;
        cout << "Tree "
             << (bst1.contains(8) ? "contains " : "does not contain ")
             << "the value " << 8 << "\n";
        cout << "Tree "
        << (bst1.contains(4) ? "contains " : "does not contain ")
        << "the value " << 4 << "\n\n";

        cout << "Test contains with multi-node tree: " << endl;
        for (int i = -5; i < 30; i++) {
                cout << "Tree "
                     << (bst2.contains(i) ? "contains " : "does not contain ")
                     << "the value " << i << "\n";
        }
        cout << endl;
}

// Function test_remove
// Parameters: 3 pointers to Nodes
// Returns: void
// Does: tests that remove function works correctly
void test_remove(BinarySearchTree &bst0,
                 BinarySearchTree &bst1,
                 BinarySearchTree &bst2) {
        cout << "Remove 5 from empty tree" << endl;
        bst0.remove(5);
        print_tree_details(bst0);

        cout << "1 node tree: " << endl;
        print_tree_details(bst1);

        cout << "Remove 6 from 1 node tree" << endl;
        bst1.remove(6);
        print_tree_details(bst1);

        cout << "Remove 4 from 1 node tree" << endl;
        bst1.remove(4);
        print_tree_details(bst1);

        cout << "Multi node tree: " << endl;
        print_tree_details(bst2);

        cout << "Remove everything from multi-node tree one by one: " << endl;
        for (int i = -5; i < 20; i++) {
                cout << "number to remove is " << i << endl;
                bst2.remove(i);
                print_tree_details(bst2);
        }
}

// provided print tree details function
void print_tree_details(BinarySearchTree &bst) {
        bst.print_tree();
        cout << "\n";
        cout << "min: "         << bst.find_min()    << "\n";
        cout << "max: "         << bst.find_max()    << "\n";
        cout << "nodes: "       << bst.node_count()  << "\n";
        cout << "count total: " << bst.count_total() << "\n";
        cout << "tree height: " << bst.tree_height() << "\n";
        cout << "\n";
}
