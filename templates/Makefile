#Makefile

#compiler
CC=g++

#compile with debug symbols
#used with gdb debugger
CFLAGS=-g


all: main test



main: template_classes.h template_methods.h \
      user_types.h basic.h arrays.h main.cpp
	$(CC) $(CFLAGS) main.cpp -o main

test: test.cpp
	$(CC) $(CFLGAS) test.cpp -o test

clean:
	rm -rf main
	rm -rf test 
