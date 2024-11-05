#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "table.h"

// Test for create table 
void test_create_table() {
    Table* table = create_table();
    assert(table != NULL);
    assert(table->root == NULL);
    assert(table->row_count == 0);
    free_table(table);
    printf("test_create_table is passed\n");
}

// Test for create row
void test_create_row() {
    int id = 1;
    const char* name = "Théophane";
    int age = 21;
    const char* school = "ESGI";

    Row* row = create_row(id, name, age, school);
    assert(row != NULL);
    assert(row->id == id);
    assert(strcmp(row->name, name) == 0);
    assert(row->age == age);
    assert(strcmp(row->school, school) == 0);

    free(row);
    printf("test_create_row is passed\n");
}

// Test for insert row
void test_insert_row(){
    Table* table = create_table();
    assert(table != NULL);

    Row* row = create_row(1,"Théophane",21,"ESGI");
    assert(row != NULL);
    
    insert_row(table, row);

    assert(table->root != NULL);
    assert(table->row_count == 1);
    assert(((Row*)table->root->data)->id == row->id);
    assert(strcmp(((Row*)table->root->data)->name, row->name) == 0);
    assert(((Row*)table->root->data)->age == row->age);
    assert(strcmp(((Row*)table->root->data)->school, row->school) == 0);

    free_table(table);
    printf("test_insert_row is passed\n");
}

int main() {
    test_create_table();
    test_create_row();
    test_insert_row();
    return 0;
}