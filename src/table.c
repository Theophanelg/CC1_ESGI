// This module is responsible for managing database tables, defining the necessary data structures and functions to manipulate tables effectively. 

#include <stdio.h>
#include <stdlib.h>
#include "table.h"

//Function to create a new table and initialize its parameters
Table* create_table(){
    Table* table = (Table*)malloc(sizeof(Table));
    if (table) {
        table->root = NULL;
        table->row_count = 0;
    }
    return table;
}
