CC=$(CROSS_COMPILE)g++
CFLAGS=-Wall -std=c99 -O0 -g -Wconversion -Wextra

all: clean communicator

communicator: communicator.o
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	rm -rf *.o communicator