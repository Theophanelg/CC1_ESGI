/*
 * table.c
 * 
 * This module provides functionality for managing tables containing rows 
 * of data, each stored as a node within a binary tree. It includes functions 
 * to create, insert, retrieve, delete, and free rows within a table structure, 
 * with each row uniquely identified by an ID.
 * 
 * Functions:
 * - create_table: Function to create a new table and initialize its parameters
 * - create_row: Function to create a new row with specified attributes and return a pointer to it
 * - insert_row: Function to insert a new row into the table
 * - select_row: Function to find a row by ID
 * - delete_row: Function to delete a row from the table by ID
 * - free_table: Frees all allocated memory associated with the table and its nodes.
 * 
 * Dependencies:
 * - stdio.h and stdlib.h: Required for input/output operations and dynamic memory allocation.
 * - table.h: Defines the structure and prototypes necessary for table and row management.
 * - btree.h: Defines binary tree-related functions used for node insertion, deletion, and searching.
 * 
 * Author: [LEGRAND Théophane]
 */
#include <stdio.h>
#include <stdlib.h>
#include "../include/table.h"
#include "../include/btree.h"
#include "../include/disk_persistence.h"


// Function to save the table
void save_table(Table* table) {
    save_table_to_file(table, "table_data.dat");
}

// Function to load the table
Table* load_table() {
    return load_table_from_file("table_data.dat");
}

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
        return;
    }
    newNode->data = row;
    newNode->left = NULL;
    newNode->right = NULL;

    if (table->root == NULL) {
        table->root = newNode;
    } else {
        insert_into_binary_tree(&(table->root), newNode);
    }
    table->row_count++;
}

// Function to find a row by ID
Row* select_row(Table* table, int id) {
    return find_row_in_tree(table->root, id);
}

// Function to delete a row from the table by ID
void delete_row(Table* table, int id) {
    table->root = delete_node(table->root, id);
}
// Function to print the entire table by calling print_node on the root node
void print_table(Table* table) {
    print_node(table->root);
}

// Function to free the allocated memory for the table
void free_table(Table* table) {
    if (table) {
        free_binary_tree(table->root);
        free(table);
    }
}
