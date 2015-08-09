CC=g++
CFLAGS=-c -std=c++11
LINKFLAGS=-std=c++11

all: simulate

simulate: simulate.o input.o
	$(CC) $(LINKFLAGS) $^ -o $@

simulate.o: simulate.cpp
	$(CC) $(CFLAGS) $^

input.o: input.cpp
	$(CC) $(CFLAGS) $^

clean:
	rm *.o simulate
