# Lists Makefile

CC=g++
CFLAGS=-g -Wall
OBJECTS=-c

all: test

test: slinkedlist.h test.cc
	$(CC) $(CFLAGS) slinkedlist.h test.cc -o $@

clean:
	rm test