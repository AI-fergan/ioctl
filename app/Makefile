CC=$(CROSS_COMPILE)g++
CFLAGS=-Wall -std=c++11 -O0 -g -Wconversion -Wextra -I.

all: clean main

main: main.o visual.o communicator.o
	$(CC) -o $@ $^ $(CFLAGS)

main.o: main.cpp
	$(CC) -c -o $@ $< $(CFLAGS)


visual.o: visual.cpp
	$(CC) -c -o $@ $< $(CFLAGS)

communicator.o: communicator.cpp
	$(CC) -c -o $@ $< $(CFLAGS)

clean:
	rm -rf *.o main
