#include "Binary_Search_Tree.h"
#include <stdio.h>
#include <stdlib.h>

'''
typedef struct BST_Node {
    struct BST_Node *left;
    struct BST_Node *right;
    int key;
} BST_Node;
'''

// Initialize the tree (set root to NULL)
void init(BST_Node **root) {
    *root = NULL;
}

// Insert a value into the tree
BST_Node* insert(BST_Node *tree, int val) {
    if (tree == NULL) {
        tree = (BST_Node *)malloc(sizeof(BST_Node));
        tree->key = val;
        tree->left = tree->right = NULL;
    } else if (val < tree->key) {
        tree->left = insert(tree->left, val);
    } else if (val > tree->key) {
        tree->right = insert(tree->right, val);
    }
    // If val == tree->key, do nothing (or handle duplicates as you wish)
    return tree;
}

// Search for a value
int get_val(BST_Node *tree, int val) {
    if (tree == NULL) return 0;
    if (val == tree->key) return 1;
    else if (val < tree->key) return get_val(tree->left, val);
    else return get_val(tree->right, val);
}

// Remove a node with a given value
BST_Node* remove_node(BST_Node *tree, int val) {
    if (tree == NULL) return NULL;

    if (val < tree->key) {
        tree->left = remove_node(tree->left, val);
    } else if (val > tree->key) {
        tree->right = remove_node(tree->right, val);
    } else {
        // Node found
        if (tree->left == NULL) {
            BST_Node *temp = tree->right;
            free(tree);
            return temp;
        } else if (tree->right == NULL) {
            BST_Node *temp = tree->left;
            free(tree);
            return temp;
        } else {
            // Find in-order successor
            BST_Node *succ = tree->right;
            while (succ->left != NULL)
                succ = succ->left;
            tree->key = succ->key;
            tree->right = remove_node(tree->right, succ->key);
        }
    }
    return tree;
}

// Free the tree
void free_tree(BST_Node *tree) {
    if (tree == NULL) return;
    free_tree(tree->left);
    free_tree(tree->right);
    free(tree);
}
