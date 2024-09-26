#include <iostream>

/*
    Explained using binary trees
    
    In-order traversal
        Go as far left, then to the root node, then to the right node. 
        Visits nodes from left to right 
        For a binary search tree, nodes are visited in non-decreasing order.

    Post-order traversal
        Visits left children, then the right children, then the root
        Used to delete a tree from leaf to root

    Pre-order traversal
        Visits the root, then left children, then right children
        Used to create a copy of a tree
*/

using std::cout;
using std::endl;

struct tree_node {
    int value;          // value stored in the node
    tree_node* left;    // pointer to the left child
    tree_node* right;   // pointer to the right child

    // constructor
    tree_node(int val) : value(val), left(nullptr), right(nullptr) {}
};

class binary_tree {
public:
    tree_node* root;

    // constructor
    binary_tree() : root(nullptr) {}

    // insert a node into the binary tree
    tree_node* insert(tree_node* node, int value) {
        // if empty tree, create a new node
        if (node == nullptr) return new tree_node(value);

        // otherwise, insert new node in recursive manner
        if (value < node->value) {
            node->left = insert(node->left, value);
        }
        else {
            node->right = insert(node->right, value);
        }

        return node;
    }

    // wrapper function for inserting into the tree
    void insert(int value) {
        root = insert(root, value);
    }

    // in-order traversal (left child, node, right child)
    void in_order_traversal(tree_node* node) {
        if (node == nullptr) return;

        // visit left subtree
        in_order_traversal(node->left);

        // visit the node
        cout << node->value << " ";

        // visit the right subtree
        in_order_traversal(node->right);
    }

    // pre-order traversal (node, left child, right child)
    void pre_order_traversal(tree_node* node) {
        if (node == nullptr) return;

        // visit node
        cout << node->value << " ";

        // visit left subtree
        pre_order_traversal(node->left);

        // visit right subtree
        pre_order_traversal(node->right);
    }

    // post-order traversal (visit left child, right child, node)
    void post_order_traversal(tree_node* node) {
        if(node == nullptr) return;

        // visit left subtree
        post_order_traversal(node->left);

        // visit right subtree
        post_order_traversal(node->right);

        // visit node
        cout << node->value << " ";
    }

    // wrapper functions
    void in_order() {
        cout << "In-order traversal: ";
        in_order_traversal(root);
        cout << endl;
    }

    void pre_order() {
        cout << "Pre-order traversal: ";
        pre_order_traversal(root);
        cout << endl;
    }

    void post_order() {
        cout << "Post_order traversal: ";
        post_order_traversal(root);
        cout << endl;
    }
};

int main () {

    // instantiate binary tree
    binary_tree tree;

    // insert values into tree
    tree.insert(10);
    tree.insert(5);
    tree.insert(15);
    tree.insert(3);
    tree.insert(7);
    tree.insert(12);
    tree.insert(20);

    // perform different traversals
    tree.in_order();
    tree.pre_order();
    tree.post_order();

    return 0;
}