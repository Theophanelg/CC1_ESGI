#ifndef BINARY_TREE_H
#define BINARY_TREE_H
#include "table.h"

// Node structure representing each element in the binary tree
typedef struct Node {
    void* data;     
    struct Node* left;     
    struct Node* right;
} Node;

//call methodes
void insert_into_binary_tree(Node* root, Node* newNode);
Row* find_row_in_tree(Node* root, int id);
Node* delete_node(Node* root, int id);
void free_binary_tree(Node* root);


#endif