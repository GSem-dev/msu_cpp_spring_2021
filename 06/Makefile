CC=g++
FLAGS= -std=c++17

all: format
	./format

format: test.o
	$(CC) $(FLAGS) test.o -o format

test.o: test.cpp format.h
	$(CC) $(FLAGS) -c test.cpp

test: test.o
	$(CC) $(FLAGS) test.o -o test
	./test
clean:
	rm -rf *.o format test
