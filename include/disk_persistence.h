#ifndef DISK_PERSISTENCE_H
#define DISK_PERSISTENCE_H

#include "table.h"

// Function to save the table to a file
void save_table_to_file(Table* table, const char* filename);

// Function to load the table from a file
Table* load_table_from_file(const char* filename);

#endif // DISK_PERSISTENCE_H
