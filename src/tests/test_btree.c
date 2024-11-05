#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include "btree.h"
#include "table.h"

//Test for insert into binary tree
void test_insert_into_binary_tree() {
    Node* root = (Node*)malloc(sizeof(Node));
    Row* rootRow = create_row(2, "Root", 20, "Root");
    root->data = rootRow;
    root->left = NULL;
    root->right = NULL;

    Row* leftRow = create_row(1, "LeftChild", 18, "Left");
    Node* leftNode = (Node*)malloc(sizeof(Node));
    leftNode->data = leftRow;
    leftNode->left = NULL;
    leftNode->right = NULL;

    insert_into_binary_tree(root, leftNode);
    assert(root->left == leftNode);

    Row* rightRow = create_row(3, "RightChild", 22, "Right");
    Node* rightNode = (Node*)malloc(sizeof(Node));
    rightNode->data = rightRow;
    rightNode->left = NULL;
    rightNode->right = NULL;

    insert_into_binary_tree(root, rightNode);
    assert(root->right == rightNode);

    printf("test_insert_into_binary_tree is passed\n");

    free_binary_tree(root);
}

int main() {
    test_insert_into_binary_tree();
    return 0;
}