#ifndef TABLE_H
#define TABLE_H

// Structure to represent a row in table
typedef struct {
    int id;
    char name[50];
    int age;
    char school[50];
} Row; 

// Node structure representing each element in the binary tree
typedef struct Node {
    void* data;     
    struct Node* left;     
    struct Node* right;
} Node;

// structure to represent a Table
typedef struct {
    Node* root;
    int row_count;
} Table;

// Call methodes
Table* create_table();
Row* create_row(int id, const char* name, int age, const char* school);
void insert_row(Table* table, Row* row);
Row* select_row(Table* table, int id);
void delete_row(Table* table, int id);
void free_table(Table* table);

#endif

