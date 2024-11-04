#ifndef BINARY_TREE_H
#define BINARY_TREE_H

// Node structure representing each element in the binary tree
typedef struct Node {
    void* data;     
    struct Node* left;     
    struct Node* right;
} Node;

//call methodes
void insert_into_binary_tree(Node* root, Node* newNode);
void free_binary_tree(Node* root);
Node* delete_node(Node* root, int id);
Row* find_row_in_tree(Node* root, int id);

#endif