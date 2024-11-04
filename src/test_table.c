#include <stdio.h>
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

int main() {
    test_create_table();
    return 0;
}