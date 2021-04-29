CC=g++
FLAGS= -std=c++17

all: format
	./format

format: test.o
	$(CC) $(FLAGS) -o format test.o

test.o: test.cpp format.h
	$(CC) $(FLAGS) -c test.cpp

clean:
	rm -rf *.o format
