//
#include <stdio.h>
#include <stdlib.h>
#include "binary_tree.h"
#include "table.h"

// Function to insert a new node into the binary tree
void insert_into_binary_tree(Node* root, Node* newNode) {
    Row* rootData = (Row*)root->data;
    Row* newNodeData = (Row*)newNode->data;

    if (newNodeData->id < rootData->id) {
        if (root->left == NULL) {
            root->left = newNode;
        } else {
            insert_into_binary_tree(root->left, newNode);
        }
    } else {
        if (root->right == NULL) {
            root->right = newNode;
        } else {
            insert_into_binary_tree(root->right, newNode);
        }
    }
}

// Function to find a node containing a Row with a specific ID in the tree
Row* find_row_in_tree(Node* root, int id) {
    if (root == NULL) {
        return NULL;
    }
    Row* rowData = (Row*)root->data;
    if (id == rowData->id) {
        return rowData;
    } else if (id < rowData->id) {
        return find_row_in_tree(root->left, id);
    } else {
        return find_row_in_tree(root->right, id);
    }
}


