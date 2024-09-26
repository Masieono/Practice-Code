#include <iostream>

/*
    Trees are a non-linear data structure where nodes are organized in a heirarchy

    root node - the very top of the tree, has no incoming edges
    leaf node - the very bottom of the tree, has no outgoing edges
    branch node - the middle of the tree, have both incoming and outgoing edges
    parent - any nodes that have outgoing edges
    child - any nodes that have incoming edges
    siblings - two or more nodes that share the same parent
    subtree - a smaller tree within a larger tree
    size - equal to the total number of nodes
    depth - number of edges below the root node
    height - number of edges above the furthests leaf node

    Binary tree - Parents only ever have at most 2 children, a right and left child
    Binary search tree -    a binary tree where the left subtree has values less than the node, 
                            and the right tree has values greater than the node

    Time complexity for insertion/deletion/search:
    - best case O(log n) when tree is balanced
    - worst case O(n) when tree is skewed like a linked list

    Tree applications -
    - File explorers
    - Databases
    - Domain name servers
    - HTML Document Object Model

*/

using std::cout;
using std::endl;

// define a node in the tree
struct tree_node {
    int value; //data stored within the node
    tree_node* left;    // pointer to the left child;
    tree_node* right;   // pointer to the right child; 

    // constructor
    tree_node(int v) : value(v), left(nullptr), right(nullptr) {}
};

// class to represent binary tree
class binary_tree {
public:
    tree_node* root;

    // constructor for empty tree
    binary_tree() : root(nullptr) {}

    // insert value into the binary tree
    void insert(int value)
    {
        root = insert_node(root, value);
    }

    void remove(int value)
    {
        root = remove_node(root, value);
    }

    // in-order traversal of the tree
    void ascending_traversal(tree_node* node)
    {
        if (node == nullptr) return;
        ascending_traversal(node->left);    // visit left subtree
        cout << node->value << " ";         // visit current node
        ascending_traversal(node->right);   // visit right subtree
    }

    // public wrapper function for ascending traversal
    void in_order()
    {
        ascending_traversal(root);
        cout << endl;
    }

    // search for a value in the tree (returns node or nullptr if not found)
    tree_node* search (int value)
    {
        return search_node(root, value);
    }

private:
    // helper function to recursively insert a new node
    tree_node* insert_node(tree_node* node, int value)
    {
        // if we find null spot, insert new node there
        if (node == nullptr) return new tree_node(value);

        // recursively insert the node in the left or right subtree
        if (value < node->value)
        {
            node->left = insert_node(node->left, value);
        }
        else {
            node->right = insert_node(node->right, value);
        }

        // return the node pointer (unchanged if no new node is inserted)
        return node;
    }

    // helper function to recursively search for a value in the tree
    tree_node* search_node(tree_node* node, int value)
    {
        // if node is null or the value matches, return the node
        if(node == nullptr || node->value == value) return node;

        // if value is less than the current node value, search left subtree
        if (value < node->value) return search_node(node->left, value);

        // otherwise, search the right subtree
        return search_node(node->right, value);
    }

    // helper function to remove a node
    tree_node* remove_node(tree_node* node, int value)
    {
        if (node == nullptr) 
        {
            return node; // base case, node not found
            cout << "Node was not found. " << endl;
        }

        if (value < node->value) 
        {
            node->left = remove_node(node->left, value);
        }
        else if (value > node->value)
        {
            node->right = remove_node(node->right, value);
        }
        else {
            // node found (node->value == value)

            // case 1: leaf node with no child
            if (node->left == nullptr && node->right == nullptr)
            {
                delete node;
                return nullptr;
            }

            // case 2: one child
            if (node->left == nullptr)
            {
                tree_node* temp = node->right;
                delete node;
                return temp;
            }
            else if (node->right == nullptr)
            {
                tree_node* temp = node->left;
                delete node;
                return temp;
            }

            // case 3: two children
            // find the in-order successor (min value in right subtree)
            tree_node* temp = find_min(node->right);
            node->value = temp->value;      // replace current node value with successor value
            node->right = remove_node(node->right, temp->value);    // remove the in-order successor
        }

        return node;
    }

    tree_node* find_min(tree_node* node)
    {
        while (node && node->left != nullptr)
        {
            node = node->left;
        }
        return node;
    }



};


int main () {

    // create a binary tree
    binary_tree tree;

    //insert values into the tree
    tree.insert(10);
    tree.insert(5);
    tree.insert(15);
    tree.insert(2);
    tree.insert(7);
    tree.insert(12);
    tree.insert(20);    

    // print the tree using in-order traversal
    cout << "In order traversal: ";
    tree.in_order();     // expected output is values sorted ascending order

    // search for a value
    int search_value = 7;
    tree_node* found_node = tree.search(search_value);

    if (found_node != nullptr)
    {
        cout << "Value " << search_value << " found in the tree!" << endl;
    }
    else {
        cout << "Value " << search_value << " not found in the tree!" << endl;
    }

    cout << "Deleting value 10 from tree" << endl;
    tree.remove(10);

    cout << "In-order traversal after deleting 10: ";
    tree.in_order(); // no ten within the list

    return 0;
}

