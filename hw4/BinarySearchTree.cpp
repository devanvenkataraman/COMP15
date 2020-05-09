/*
 * BinarySearchTree.cpp
 * COMP15
 * Spring 2020
 *
 * Author: Devan Venkataraman
 *
 * Implementation of the Binary Search Tree class.
 * Behaves like a standard BST except that it handles multiplicity
 * If you insert a number twice  and then remove it once, then it will
 * still be in the data structure
 */

#include <cstring>
#include <iostream>
#include <limits>

#include "BinarySearchTree.h"

using namespace std;

// default constructor
BinarySearchTree::BinarySearchTree()
{
        root = nullptr;
}

// destructor
BinarySearchTree::~BinarySearchTree()
{
        // walk tree in post-order traversal and delete
        post_order_delete(root);
        root = nullptr;  // not really necessary, since the tree is going
                         // away, but might want to guard against someone
                         // using a pointer after deleting
}

// Function post_order_delete
// Parameters: pointer to a Node
// Returns: void
// Does: deletes the tree in post order fashion
void BinarySearchTree::post_order_delete(Node *node)
{
        if (node == nullptr) {
                return;
        }
        post_order_delete(node->left);
        post_order_delete(node->right);

        delete node;
}

// copy constructor
BinarySearchTree::BinarySearchTree(const BinarySearchTree &source)
{
        // use pre-order traversal to copy the tree
        root = pre_order_copy(source.root);
}

// assignment overload
BinarySearchTree &BinarySearchTree::operator=(const BinarySearchTree &source)
{
        if (this != &source) {
                post_order_delete(root);
                root = pre_order_copy(source.root);
        }

        return *this;
}

// Function pre_order_copy
// Parameters: pointer to a Node
// Returns: pointer to root Node
// Does: copies an entire tree (used by copy constructor)
BinarySearchTree::Node *BinarySearchTree::pre_order_copy(Node *node) const
{
        if (node == nullptr) {
                return nullptr;
        }
        else {
                Node *new_node = new Node;
                new_node->data = node->data;
                new_node->count = node->count;
                new_node->left = pre_order_copy(node->left);
                new_node->right = pre_order_copy(node->right);
                return new_node;
        }
}

// Function find_min
// Parameters: none
// Returns: int minimum data value
// Does: public version of find_min, calls private version
int BinarySearchTree::find_min() const
{
        if (root == nullptr)
                return numeric_limits<int>::max(); // INT_MAX

        return find_min(root)->data;
}

// Function find_min
// Parameters: pointer to a Node
// Returns: pointer to a Node
// Does: finds the node with minimum data value stored in the tree
BinarySearchTree::Node *BinarySearchTree::find_min(Node *node) const
{
        Node *current_node = node;
        while (current_node->left != nullptr) {
                current_node = current_node->left;
        }

        return current_node;
}

// Function find_max
// Parameters: none
// Returns: int minimum data value
// Does: public version of find_max, calls private version
int BinarySearchTree::find_max() const
{
        // is this right?? copied from above
        if (root == nullptr)
                return numeric_limits<int>::max(); // INT_MAX

        return find_max(root)->data;
}

// Function find_max
// Parameters: pointer to a Node
// Returns: pointer to a Node
// Does: finds the node with maximum data value stored in the tree
BinarySearchTree::Node *BinarySearchTree::find_max(Node *node) const
{
        Node *current_node = node;
        while (current_node->right != nullptr) {
                current_node = current_node->right;
        }

        return current_node;
}

// Function contains
// Parameters: int value
// Returns: boolean
// Does: public version of contains, calls private version
bool BinarySearchTree::contains(int value) const
{
        return contains(root, value);
}

// Function contains
// Parameters: pointer to a Node, int value
// Returns: boolean
// Does: checks tree to see if data value exists in tree
bool BinarySearchTree::contains(Node *node, int value) const
{
        if (node == nullptr) {
                return false;
        }
        else if (node->data == value) {
                return true;
        }
        else if (value < node->data) {
                return contains(node->left, value);
        }
        else {
                return contains(node->right, value);
        }
}

// Function insert
// Parameters: int value
// Returns: void
// Does: public version of insert, calls private version
void BinarySearchTree::insert(int value)
{
        root = insert(root, value);
}

// Function insert
// Parameters: pointer to Node, pointer to Node's parent, int value
// Returns: Pointer to a node
// Does: Inserts node if not already in tree, increases count if it is
BinarySearchTree::Node *BinarySearchTree::insert(Node *node, int value)
{
        if (node == nullptr) {
                node = new Node;
                node->data = value;
                node->count = 1;
                node->left = nullptr;
                node->right = nullptr;
                return node;
        }
        else if (value == node->data) {
                node->count++;
                return node;
        }
        else if (value > node->data) {
                node->right = insert(node->right, value);
                return node;
        }
        else {
                node->left = insert(node->left, value);
                return node;
        }
}

// Function remove
// Parameters: int value
// Returns: void
// Does: public version of remove, calls private version
bool BinarySearchTree::remove(int value)
{
        return remove(root, nullptr, value);
}

// Function remove
// Parameters: pointer to Node, pointer to Node's parent, int value
// Returns: void
// Does: private version of remove - removes a given node if in the tree
bool BinarySearchTree::remove(Node *node, Node *parent, int value)
{
        if (node == nullptr) {
                return false;
        }
        if (value < node->data) {
                return remove(node->left, node, value);
        }
        else if (value > node->data) {
                return remove(node->right, node, value);
        }
        // we've found the node
        else {
                // count > 1, just decrease count
                if (node->count > 1) {
                        node->count--;
                        return true;
                }
                // if count is 1, need to manipulate tree
                remove_children(node, parent, value);
                return true;
        }
}

// Function tree_height
// Parameters: none
// Returns: int
// Does: public version of tree_height, calls private version
int BinarySearchTree::tree_height() const
{
        return tree_height(root);
}

// Function tree_height
// Parameters: none
// Returns: int
// Does: private version of tree_height, finds height of the tree
int BinarySearchTree::tree_height(Node *node) const
{
        // if it's empty, height is -1
        if (node == nullptr) {
                return -1;
        }
        else {
                // find height of node's left and right subtree
                int height_left = tree_height(node->left);
                int height_right = tree_height(node->right);

                // return the larger one, + 1 for the current node
                if (height_left > height_right) {
                        return height_left + 1;
                }
                else {
                        return height_right + 1;
                }
        }
}

// Function node_count
// Parameters: none
// Returns: int
// Does: public version of node_count, calls private version
int BinarySearchTree::node_count() const
{
        return node_count(root);
}

// Function node_count
// Parameters: none
// Returns: int
// Does: a pre order traversal of the tree, counting it's nodes
int BinarySearchTree::node_count(Node *node) const
{
        if (node == nullptr) {
                return 0;
        }
        else {
                return 1 + node_count(node->left) + node_count(node->right);
        }
}

// Function count_total
// Parameters: none
// Returns: int
// Does: public version of count_total, calls private version
int BinarySearchTree::count_total() const
{
        return count_total(root);
}

// Function count_total
// Parameters: none
// Returns: int
// Does: counts the total value of tree (node x count)
int BinarySearchTree::count_total(Node *node) const
{
        if (node == nullptr) {
                return 0;
        }
        else {
                return (node->count * node->data)
                + count_total(node->left)
                + count_total(node->right);
        }
}

// provided find parent function
BinarySearchTree::Node *BinarySearchTree::find_parent(Node *node,
                                                      Node *child) const
{
        if (node == nullptr)
                return nullptr;

        // if either the left or right is equal to the child,
        // we have found the parent
        if (node->left == child or node->right == child) {
                return node;
        }

        // Use the binary search tree invariant to walk the tree
        if (child->data > node->data) {
                return find_parent(node->right, child);
        } else {
                return find_parent(node->left, child);
        }
}

// use the printPretty helper to make the tree look nice
void BinarySearchTree::print_tree() const
{
        size_t      numLayers  = tree_height() + 1;
        size_t      levelWidth = 4;
        const char *rootPrefix = "-> ";

        // Need numLayers * levelWidth characters for each layer of tree.
        // Add an extra levelWidth characters at front to avoid if statement
        // 1 extra char for nul character at end
        char *start = new char[(numLayers + 1) * levelWidth + 1];

        print_tree(root, start + levelWidth, start + levelWidth, rootPrefix);
        delete[] start;
}

// Logic and Output Reference:
// https://www.techiedelight.com/c-program-print-binary-tree/
void BinarySearchTree::print_tree(Node *node, char *const currPos,
                                  const char *const fullLine,
                                  const char *const branch) const
{
        if (node == nullptr)
                return;

        // 4 characters + 1 for nul terminator
        using TreeLevel                    = char[5];
        static const int       levelLength = sizeof(TreeLevel) - 1;
        static const TreeLevel UP = ".-- ", DOWN = "`-- ", EMPTY = "    ",
                               CONNECT = "   |";
        // Copies prev into dest and advances dest by strlen(prev)
        auto set = [](char *dest, const char *prev) {
                size_t p = strlen(prev);
                return (char *)memcpy(dest, prev, p) + p;
        };

        print_tree(node->right, set(currPos, EMPTY), fullLine, UP);

        // Clear any characters that would immediate precede the "branch"
        // Don't need to check for root (i.e start of array),fullLine is padded
        set(currPos - levelLength, EMPTY);

        // Terminate fullLine at current level
        *currPos = '\0';

        std::cerr << fullLine << branch << node->data
                  << (node->count > 1 ? "*" : "") << endl;

        // Connect upper branch to parent
        if (branch == UP)
                set(currPos - levelLength, CONNECT);

        // Connect lower branch to parent
        print_tree(node->left, set(currPos, CONNECT), fullLine, DOWN);
}

// Function remove_children
// Parameters: pointer to Node, pointer to Node's parent, int value
// Returns: void
// Does: Handles first two remove cases: if node to remove has either
//       no children or just a right child. Calls remove_children2
//       if either of the other two cases
void BinarySearchTree::remove_children(Node *node, Node *parent, int value) {
        // no children
        if (node->left == nullptr and node->right == nullptr) {
                if (parent == nullptr) {
                        root = nullptr;
                }
                else if (value < parent->data) {
                        parent->left = nullptr;
                }
                else {
                        parent->right = nullptr;
                }
                delete node;
        }
        // has a right child
        else if (node->left == nullptr) {
                if (parent == nullptr) {
                        root = node->right;
                }
                else if (value < parent->data) {
                        parent->left = node->right;
                }
                else {
                        parent->right = node->right;
                }
                delete node;
        }
        else {
                // put other 2 cases in a diff function for length sake
                remove_children2(node, parent, value);
        }
}

// Function remove_children2
// Parameters: pointer to Node, pointer to Node's parent, int value
// Returns: void
// Does: Handles second two remove cases: if node to remove has only a
//       left child, or if it has two children
void BinarySearchTree::remove_children2(Node *node, Node *parent, int value) {
        // has a left child
        if (node->right == nullptr) {
                if (parent == nullptr) {
                        root = node->left;
                }
                else if (value < parent->data) {
                        parent->left = node->left;
                }
                else {
                        parent->right = node->left;
                }
                delete node;
        }
        // has two children
        else {
                // find the min node on the node's right subtree,
                // this will take node's spot
                Node *min_right_node = find_min(node->right);
                // write over the info of the node to be removed
                node->data = min_right_node->data;
                node->count = min_right_node->count;
                // need to ensure the node gets removed, make its count 1,
                // okay because we've already copied over its actual count,
                // then call remove on that node that moved
                min_right_node->count = 1;
                remove(node->right, node, min_right_node->data);
        }
}
