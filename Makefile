CC = gcc 
FLAGS = -Wall -Werror -ansi -pedantic

all : main 

main : main.c
	$(CC) $(FLAGS) -c $^ -o $@

clean : rm -rf *.o
