# Lists Makefile

CC=g++
CFLAGS=-g -Wall

all: s_test d_test

s_test: slinkedlist.h s_test.cc
	$(CC) $(CFLAGS) slinkedlist.h s_test.cc -o $@

d_test: dlinkedlist.h d_test.cc
	$(CC) $(CFLAGS) dlinkedlist.h d_test.cc -o $@


clean:
	rm *test
