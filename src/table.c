// This module is responsible for managing database tables, defining the necessary data structures and functions to manipulate tables effectively. 

#include <stdio.h>
#include <stdlib.h>
#include "table.h"

//Function to create a new table and initialize its parameters
Table* create_table(){
    Table* table = (Table*)malloc(sizeof(Table));
    
    if (!table) {
        fprintf(stderr, "Memory allocation failed for new node\n");
        return;
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
        return;
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

// Function to free the allocated memory for the table
void free_table(Table* table) {
    if (table) {
        free_binary_tree(table->root);
        free(table);
    }
}
