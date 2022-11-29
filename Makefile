CC = g++
TARGET = deq
CFLAGS = -g -Wall -Wextra
#Complies showing all errors and warnings

all: deq

#List the object files needed to create the executable file.

$(TARGET): main.o deque.o
	   $(CC) $(CFlags) -o $(TARGET) main.o deque.o

#Creates the rules need to link everything to main

main.o: main.cpp deque.h
	$(CC) $(CFLAGS) -c main.cpp

#Creates the rules for deque.o

deque.o: deque.cpp deque.h
	         $(CC) $(CFLAGS) -c deque.cpp

#Creates a blank slate (done by 'make clean')

clean:
	$(RM) deq *.o *~
