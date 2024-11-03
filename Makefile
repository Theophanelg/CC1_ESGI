#Compiler and flags 
CC = gcc 
FLAGS = -Wall -Werror -ansi -pedantic

#Target executable
TARGET = main

#Source and object files
SRCS = main.c table.c btree.c sql_commands.c disk_persistence.c utils.c
OBJS = $(SRCS:.c=.o)

# Link object files to create the final executable
$(TARGET): $(OBJS)
	$(CC) $(FLAGS) -o $(TARGET) $(OBJS)

# Compile each .c file into .o object files
%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

# Clean up generated files
clean:
	rm -f $(OBJS) $(TARGET)
