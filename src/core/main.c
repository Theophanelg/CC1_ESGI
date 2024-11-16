#include <stdio.h>
#include <stdlib.h>
#include "../include/table.h"
#include "../include/disk_persistence.h"
#include "../include/btree.h"

int main() {
    // Create a table
    Table* table = malloc(sizeof(Table));
    table->root = NULL;
    table->row_count = 0;

    // Create data rows
    Row* row1 = create_row(1, "Théophane", 21, "ESGI 1");
    Row* row2 = create_row(2, "Encore Théophane", 22, "ESGI 2");
    Row* row3 = create_row(3, "Quelqu'un d'autre", 23, "Paris School");

    // Insert rows into the table
    insert_row(table, row1);
    insert_row(table, row2);
    insert_row(table, row3);

    // Display the table contents
    printf("Table contents:\n");
    print_table(table);

    // Save the table to a file
    save_table_to_file(table, "table.dat");

    // Free allocated memory
    free(row1);
    free(row2);
    free(row3);
    free(table);

    return 0;
}