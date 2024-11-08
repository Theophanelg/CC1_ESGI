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

//Test for select row
void test_select_row(){
    Table* table = create_table();
    assert(table != NULL);

    Row* row1 = create_row(1, "Théophane", 21, "ESGI");
    Row* row2 = create_row(2, "Théophane Numéro 2", 22, "Toujours l'ESGI");
    Row* row3 = create_row(3, "Théophane numéro 3", 23, "Toujours et encore l'ESGI");

    insert_row(table, row1);
    insert_row(table, row2);
    insert_row(table, row3);

    assert(select_row(table, 1) == row1);
    assert(select_row(table, 2) == row2);
    assert(select_row(table, 3) == row3);
    assert(select_row(table, 4) == NULL);

    free_table(table);
    printf("test_select_row is passed\n");
}

//Test for delete row
void test_delete_row(){
    Table* table = create_table();
    assert(table !=NULL);
    
    Row* row1 = create_row(1, "Théophane", 21, "ESGI");
    Row* row2 = create_row(2, "Théophane Numéro 2", 22, "Toujours l'ESGI");
    Row* row3 = create_row(3, "Théophane numéro 3", 23, "Toujours et encore l'ESGI");

    insert_row(table, row1);
    insert_row(table, row2);
    insert_row(table, row3);

    delete_row(table, 2);
    assert(select_row(table,2) == NULL);
    assert(select_row(table, 1) == row1);
    assert(select_row(table, 3) == row3);

    delete_row(table, 4);
    free_table(table);
    printf("test_delete_row is passed\n");
}


//Test for free table
void test_free_table() {
    Table* table = create_table();
    assert(table != NULL);

    Row* row1 = create_row(1, "Théophane", 21, "ESGI");
    Row* row2 = create_row(2, "Théophane Numéro 2", 22, "Toujours l'ESGI");
    Row* row3 = create_row(3, "Théophane numéro 3", 23, "Toujours et encore l'ESGI");

    insert_row(table, row1);
    insert_row(table, row2);
    insert_row(table, row3);

    free_table(table);

    printf("test_free_table is passed\n");
}

int main() {
    test_create_table();
    test_create_row();
    test_insert_row();
    test_select_row();
    test_delete_row();
    test_free_table();
    return 0;
}