// This module is responsible for managing database tables, defining the necessary data structures and functions to manipulate tables effectively. 

#include <stdio.h>
#include <stdlib.h>
#include "table.h"

// Function to create a new table and initialize its parameters
Table* create_table(){
    Table* table = (Table*)malloc(sizeof(Table));
    
    if (!table) {
        fprintf(stderr, "Memory allocation failed for new node\n");
        return NULL;
    }
    
    if (table) {
        table->root = NULL;
        table->row_count = 0;
    }
    return table;
}

// Function to create a new row with specified attributes and return a pointer to it
Row* create_row(int id, const char* name, int age, const char* school) {
    Row* row = (Row*)malloc(sizeof(Row));
    if (!row) {
        fprintf(stderr, "Memory allocation failed for new row\n");
        return NULL;
    }
    row->id = id;
    snprintf(row->name, sizeof(row->name), "%s", name);
    row->age = age;
    snprintf(row->school, sizeof(row->school), "%s", school);
    return row;
}

// Function to insert a new row into the table
void insert_row(Table* table, Row* row) {
    Node* newNode = (Node*)malloc(sizeof(Node));

    if (!newNode) {
        fprintf(stderr, "Memory allocation failed for new node\n");
        return NULL;
    }

    newNode->data = row;
    newNode->left = NULL;
    newNode->right = NULL;

    if (table->root == NULL) {
        table->root = newNode;
    } else {
        insert_into_binary_tree(table->root, newNode);
    }
}

// Function to find a row by ID
Row* select_row(Table* table, int id) {
    return find_row_in_tree(table->root, id);
}

// Helper function to search for a row by ID in the binary tree
Row* find_row_in_tree(Node* root, int id) {
    if (root == NULL) {
        return NULL; 
    }
    if (id == root->data->id) {
        return root->data;
    } else if (id < root->data->id) {
        return find_row_in_tree(root->left, id);
    } else {
        return find_row_in_tree(root->right, id);
    }
}

// Function to delete a row from the table by ID
void delete_row(Table* table, int id) {
    table->root = delete_node(table->root, id);
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

// Recursive function to free the memory allocated for all nodes in the binary tree
void free_binary_tree(Node* root) {
    if (root == NULL) {
        return;
    }
    free_binary_tree(root->left);
    free_binary_tree(root->right);
    free(root->data);
    free(root);
}

// Function to free the allocated memory for the table
void free_table(Table* table) {
    if (table) {
        free_binary_tree(table->root);
        free(table);
    }
}
