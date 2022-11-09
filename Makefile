CC = g++
CFLAGS = -Wall -g

all: main

#tests.o: tests.cpp f_lab2_linkedlistsequence.h f_lab2_arraysequence.h
#	$(CC) $(CFLAFS) -c tests.cpp

main.o: main.cpp Sequence/f_lab2_sequence.h DA/f_lab2_arraysequence.h DA/f_lab2_dynamicarray.h LL/f_lab2_linkedlist.h LL/f_lab2_linkedlistsequence.h 
	$(CC) $(CFLAGS) -c main.cpp

main: main.o
	$(CC) $(CFLAGS) -o main main.o

clean:
	rm -rf *.o main


#-0fast 
