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

int main() {
    test_create_table();
    test_create_row();
    return 0;
}