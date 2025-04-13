#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

// Definition of a binary search tree node
typedef struct BST_Node {
    struct BST_Node *left;
    struct BST_Node *right;
    int key;
} BST_Node;

// Initializes the root to NULL
void init(BST_Node **root);

// Inserts a value into the BST
BST_Node* insert(BST_Node *tree, int val);

// Searches for a value in the BST, returns 1 if found, 0 otherwise
int get_val(BST_Node *tree, int val);

// Removes a value from the BST
BST_Node* remove_node(BST_Node *tree, int val);

// Frees all nodes in the BST
void free_tree(BST_Node *tree);

#endif // BINARY_SEARCH_TREE_H
