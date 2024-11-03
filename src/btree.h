#ifndef BINARY_TREE_H
#define BINARY_TREE_H

// Node structure representing each element in the binary tree
typedef struct Node {
    void* data;     
    struct Node* left;     
    struct Node* right;
} Node;

#endif