#ifndef TABLE_H
#define TABLE_H

#include <stdlib.h>
#include "btree.h"

// Structure to represent a row in table
typedef struct {
    int id;
    char name[50];
    int age;
    char school[50];
} Row; 

typedef struct {
    Node* root;
    size_t row_count;
} Table;

// Call methodes
Table* create_table();
Row* create_row(int id, const char* name, int age, const char* school);
void insert_row(Table* table, Row* row);
Row* select_row(Table* table, int id);
void delete_row(Table* table, int id);
void free_table(Table* table);

#endif

