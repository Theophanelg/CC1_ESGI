/*
 * binary_tree.c
 * 
 * This module provides functions to manage a binary tree data structure 
 * specifically for storing and organizing rows based on unique IDs. The 
 * functions included allow for insertion, search, deletion, and memory 
 * deallocation of tree nodes, each containing a row of data.
 * 
 * Functions:
 * - insert_into_binary_tree: Inserts a node into the binary tree.
 * - find_row_in_tree: Searches for a row by ID within the tree, returning a pointer to the row if found.
 * - delete_node: Removes a node by ID from the tree, adjusting connections to maintain tree structure.
 * - free_binary_tree: Recursively frees memory for all nodes in the tree.
 * 
 * Dependencies:
 * - table.h: Defines the Row structure used as the data payload in each node.
 * - binary_tree.h: Contains the structure definitions and prototypes for this module.
 * 
 * Author: [LEGRAND Théophane]
 */ 
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

// Helper function to delete a node from the binary tree
Node* delete_node(Node* root, int id) {
    if (root == NULL) {
        return NULL;
    }

    if (id < root->data->id) {
        root->left = delete_node(root->left, id);
    } else if (id > root->data->id) {
        root->right = delete_node(root->right, id);
    } else {
        if (root->left == NULL && root->right == NULL) {
            free(root->data);
            free(root);
            return NULL;
        }
        else if (root->left == NULL) {
            Node* temp = root->right;
            free(root->data);
            free(root);
            return temp;
        } else if (root->right == NULL) {
            Node* temp = root->left;
            free(root->data);
            free(root);
            return temp;
        }
    }
    return root;
}

// Function to free all nodes in the binary tree
void free_binary_tree(Node* root) {
    if (root == NULL) {
        return;
    }
    free_binary_tree(root->left);
    free_binary_tree(root->right);
    free(root->data);
    free(root);
}
