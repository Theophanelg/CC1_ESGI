// 
#include <stdio.h>
#include <stdlib.h>
#include "binary_tree.h"
#include "table.h"

void insert_into_binary_tree(Node* root, Node* newNode) {
    Row* rootData = (Row*)root->data;
    Row* newNodeData = (Row*)newNode->data;

    if (newNodeData->id < rootData->id) {
        if (root->left == NULL) {
            root->left = newNode;
        } else {
            insert_into_binary_tree(root->left, newNode);
        }
    } else {
        if (root->right == NULL) {
            root->right = newNode;
        } else {
            insert_into_binary_tree(root->right, newNode);
        }
    }
}