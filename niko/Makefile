#simple Makefile

CC=g++
CFLAGS=-g

all: main_structures main_pointers main_functions

main_structures: main_structures.cpp
	$(CC) $(CFLAGS) main_structures.cpp -o structures

main_pointers: main_pointers.cpp
	$(CC) $(CFLAGS) main_pointers.cpp -o pointers

main_functions: main_functions.cpp
	$(CC) $(CFLAGS) main_functions.cpp -o functions

clean:
	rm structures
	rm pointers
	rm functions
