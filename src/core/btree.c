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
 * - btree.h: Contains the structure definitions and prototypes for this module.
 * 
 * Author: [LEGRAND Théophane]
 */ 
#include <stdio.h>
#include <stdlib.h>
#include "../include/btree.h"

// Function to insert in new node in binary tree
void insert_into_binary_tree(Node** root, Node* newNode) {
    if (!root || !newNode || !newNode->data) {
        printf("Invalid input to insert_into_binary_tree\n");
        return;
    }

    if (*root == NULL) {
        *root = newNode;
        printf("Inserted at root, Node ID: %d\n", ((Row*)newNode->data)->id);
        return;
    }

    Row* rootData = (Row*)(*root)->data;
    Row* newNodeData = (Row*)newNode->data;

    if (newNodeData->id < rootData->id) {
        if ((*root)->left == NULL) {
            (*root)->left = newNode;
            printf("Inserted at left of Node ID: %d\n", rootData->id);
        } else {
            insert_into_binary_tree(&(*root)->left, newNode);
        }
    } else {
        if ((*root)->right == NULL) {
            (*root)->right = newNode;
            printf("Inserted at right of Node ID: %d\n", rootData->id);
        } else {
            insert_into_binary_tree(&(*root)->right, newNode);
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

// Function for delete node in binary tree
Node* delete_node(Node* root, int id) {
    if (root == NULL) {
        return NULL;
    }

    if (root->data == NULL) {
        fprintf(stderr, "Error: root->data is NULL.\n");
        return root;
    }

    Row* rowData = (Row*)root->data;
    if (id < rowData->id) {
        root->left = delete_node(root->left, id);
    } else if (id > rowData->id) {
        root->right = delete_node(root->right, id);
    } else {
        if (root->left == NULL) {
            Node* temp = root->right;
            free(rowData);
            free(root);
            return temp;
        } else if (root->right == NULL) {
            Node* temp = root->left;
            free(rowData);
            free(root);
            return temp;
        } else {
            Node* successor = root->right;
            while (successor->left != NULL) {
                successor = successor->left;
            }

            Row* successorData = (Row*)successor->data;
            rowData->id = successorData->id;
            snprintf(rowData->name, sizeof(rowData->name), "%s", successorData->name);
            rowData->age = successorData->age;
            snprintf(rowData->school, sizeof(rowData->school), "%s", successorData->school);

            root->right = delete_node(root->right, successorData->id);
        }
    }
    return root;
}

// Function to print the data stored in a node and its child nodes recursively
void print_node(Node* node) {
    if (node != NULL) {
        Row* row = (Row*)node->data;
        printf("Node ID : %d\n", row->id);
        printf("Prénom : %s\n", row->name);
        printf("Age : %d\n", row->age);
        printf("Ecole : %s\n", row->school);
        printf("-------------------------\n");

        print_node(node->left);
        print_node(node->right);
    }
}

// Function to free all nodes in the binary tree
void free_binary_tree(Node* root) {
    if (root == NULL) {
        return;
    }

    free_binary_tree(root->left);
    free_binary_tree(root->right);

    if (root->data != NULL) {
        free(root->data);
    }
    free(root);
}