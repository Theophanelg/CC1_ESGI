/*
 * disk_persistence.c
 *
 * This module handles saving data to and loading data from disk, providing persistence
 * for the database across sessions. It includes functions for writing and reading rows,
 * as well as saving and loading entire tables to and from disk.
 *
 * Functions:
 * - write_row_to_file: Function to write a row to a file in binary format.
 * - read_row_from_file: Function to read a row from a file in binary format.
 * - save_table_to_file: Function to save the entire table to a file, including all rows.
 * - load_table_from_file: Function to load a table from a file, reconstructing the table and its rows.
 *
 * Dependencies:
 * - stdio.h: Provides functions for file handling (e.g., fopen, fread, fwrite).
 * - stdlib.h: Required for dynamic memory allocation (e.g., malloc).
 * - disk_persistence.h: Defines the prototypes for the disk persistence functions, 
 *   as well as the structures used for row and table management.
 * - table.h: Defines the structure for the table, which is used to manage rows.
 * 
 * Author: [LEGRAND Théophane]
 */
#include <stdio.h>
#include <stdlib.h>
#include "disk_persistence.h"

// Function to write a row to a file
void write_row_to_file(FILE* file, Row* row) {
    fwrite(&row->id, sizeof(int), 1, file);
    fwrite(row->name, sizeof(char), 50, file);
    fwrite(&row->age, sizeof(int), 1, file);
    fwrite(row->school, sizeof(char), 50, file);
}

// Function to read a row from a file
Row* read_row_from_file(FILE* file) {
    Row* row = (Row*)malloc(sizeof(Row));
    fread(&row->id, sizeof(int), 1, file);
    fread(row->name, sizeof(char), 50, file);
    fread(&row->age, sizeof(int), 1, file);
    fread(row->school, sizeof(char), 50, file);
    return row;
}

// Function to save the entire table to a file
void save_table_to_file(Table* table, const char* filename) {
    FILE* file = fopen(filename, "wb");
    if (file == NULL) {
        perror("Unable to open the file for writing");
        return;
    }
    fwrite(&table->row_count, sizeof(int), 1, file);

    Node* current_node = table->root;
    if (current_node != NULL) {
        write_row_to_file(file, (Row*)current_node->data);
    }

    fclose(file);
}

// Function to load the table from a file
Table* load_table_from_file(const char* filename) {
    Table* table = (Table*)malloc(sizeof(Table));
    if (table == NULL) {
        perror("Memory allocation failed for table");
        return NULL;
    }

    FILE* file = fopen(filename, "rb");
    if (file == NULL) {
        perror("Unable to open the file for reading");
        return NULL;
    }
    fread(&table->row_count, sizeof(int), 1, file);

    while (!feof(file)) {
        Row* row = read_row_from_file(file);
        if (row != NULL) {
            insert_row(table, row);
        }
    }

    fclose(file);
    return table;
}
