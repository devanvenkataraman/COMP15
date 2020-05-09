// Lab 6 - BeeEs Tees
// Author: Devan Venkataraman
// Date: 2/25/20
// BSTree.h

class BST
{
public:
    	BST();
	~BST();

        void unbalancedInsert(int v);
        void inOrder();
        void preOrder();
        void postOrderDelete();
        void levelOrder();
private:
        struct BSTNode {
		int      value;
		BSTNode *left;
		BSTNode *right;
        };
        BSTNode *root;

        BSTNode *unbalancedInsert(BSTNode *root, int v);
        void     inOrder         (BSTNode *root);
        void     preOrder        (BSTNode *root);
        void     levelOrder      (BSTNode *root);
        void     postOrderDelete (BSTNode *root);

        BSTNode *newBSTNode      (int v);
        BSTNode *newBSTNode      (int v, BSTNode *left, BSTNode *right);
};
