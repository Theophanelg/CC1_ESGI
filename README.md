# CC1 ESGI

## Legrand Théophane 3SI5

# Binary Tree Table Management System
## Description

This project is a simple implementation of a table management system using a binary tree data structure in C. Each table consists of rows containing information about individuals, such as their ID, name, age, and school. The project includes functionalities to:

    Insert rows into a binary tree structure.
    Print the contents of the table (tree traversal).
    Save the table's data to a file for persistence.
    Load the table data back from the file.

This project demonstrates key concepts in data structures, file I/O, and memory management in C.

## Features

    Insert Rows: Dynamically adds rows into the table, organizing them in a binary tree.
    Print Table: Displays the entire table content using an in-order tree traversal.
    Save to File: Serializes the table and saves it to a binary file.
    Load from File: Reads the serialized data to restore the table.

## Project Structure

    CC1_ESGI/
    ├── include/
    │   ├── btree.h             # Header for binary tree operations
    │   ├── disk_persistence.h  # Header for file persistence functions
    │   └── table.h             # Header for table and row operations
    ├── src/
    │   ├── core/
    │   │   ├── btree.c         # Implementation of binary tree functions
    │   │   ├── disk_persistence.c # Implementation of file I/O functions
    │   │   ├── table.c         # Implementation of table and row-related functions
    │   │   └── main.c          # Main program
    │   ├── tests/
    │   │   ├── test_btree.c    # Test for binary tree functions
    │   │   └── test_table.c    # Test for table and row functions
    │   ├── repl.c
    ├── obj/                    # Compiled object files
    ├── Makefile                # Build automation script
    └── README.md               # Project documentation

## Installation

    Clone the repository:

git clone <repository_url>
cd <repository_name>

Compile the project using the provided Makefile:

make

## Usage

    Run the program:

./main

gdb ./main

The program will:

    Insert predefined rows into the table.
    Print the table's contents to the console.
    Save the table to a file named table.dat.

Output example:

    Table contents:
    Node ID : 1
    Prénom : Théophane
    Age : 21
    Ecole : ESGI 1
    -------------------------
    Node ID : 2
    Prénom : Encore Théophane
    Age : 22
    Ecole : ESGI 2
    -------------------------
    Node ID : 3
    Prénom : Quelqu'un d'autre
    Age : 23
    Ecole : Paris School
    -------------------------

## Requirements

    GCC Compiler
    Makefile support
    Linux or Windows environment with MinGW/Cygwin for Windows
    GDB

## License

This project is licensed under the AGPL-3.0 license.
