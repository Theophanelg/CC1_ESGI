#ifndef BINARY_TREE_H
#define BINARY_TREE_H
#include "../include/table.h"

//call methodes
void insert_into_binary_tree(Node** root, Node* newNode);
Row* find_row_in_tree(Node* root, int id);
Node* delete_node(Node* root, int id);
void print_node(Node* node);
void free_binary_tree(Node* root);

#endif