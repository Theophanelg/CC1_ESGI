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

// Test for finding a row by ID
void test_find_row_in_tree() {
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

    Row* foundRow = find_row_in_tree(root, 1);
    assert(foundRow != NULL && foundRow->id == 1);
    assert(strcmp(foundRow->name, "LeftChild") == 0);

    foundRow = find_row_in_tree(root, 99);
    assert(foundRow == NULL);

    printf("test_find_row_in_tree is passed\n");

    free_binary_tree(root);
}

// Test for deleting a node from the binary tree
void test_delete_node() {
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

    Row* rightRow = create_row(3, "RightChild", 22, "Right");
    Node* rightNode = (Node*)malloc(sizeof(Node));
    rightNode->data = rightRow;
    rightNode->left = NULL;
    rightNode->right = NULL;

    insert_into_binary_tree(root, leftNode);
    insert_into_binary_tree(root, rightNode);

    root = delete_node(root, 1);
    Row* foundRow = find_row_in_tree(root, 1);
    assert(foundRow == NULL);

    root = delete_node(root, 3);
    foundRow = find_row_in_tree(root, 3);
    assert(foundRow == NULL);

    printf("test_delete_node is passed\n");

    free_binary_tree(root);
}

// Test for freeing the binary tree
void test_free_binary_tree() {
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

    free_binary_tree(root);

    printf("test_free_binary_tree is passed\n");
}

int main() {
    test_insert_into_binary_tree();
    test_find_row_in_tree();
    test_delete_node();
    test_free_binary_tree();
    return 0;
}