#ifndef TABLE_H
#define TABLE_H

#include <stdlib.h>
#include "btree.h"

//Structure to represent a row in table
typedef struct {
    int id;
    char name[50];
    int age;
    char school[50];
} Row; 

//Structure to represent a table, which could contain a binary tree of rows
typedef struct Node Node;

typedef struct {
    Node* root;
    size_t row_count;
} Table;

#endif

