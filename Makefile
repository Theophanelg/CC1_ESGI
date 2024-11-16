# Variables
CC = gcc
CFLAGS = -Wall -Werror -Iinclude
OBJ_DIR = obj
SRC_DIR = src/core

# List of object files
OBJ_FILES = $(OBJ_DIR)/main.o $(OBJ_DIR)/table.o $(OBJ_DIR)/btree.o $(OBJ_DIR)/disk_persistence.o

# Default target
all: main

# Rule to create the main executable
main: $(OBJ_FILES)
	$(CC) $(CFLAGS) -o $@ $^

# Compilation of source files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c -o $@ $<

# Create obj folder if it doesn't exist
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Clean up generated files
clean:
	rm -rf $(OBJ_DIR) main
