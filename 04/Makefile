CC=g++
FLAGS= -std=c++17 -Werror -Wall -fsanitize=address

all: big
	./big
big: BigInt.o test.o
	$(CC) $(FLAGS)   BigInt.o test.o -o big

BigInt.o : BigInt.cpp BigInt.hpp
	$(CC) $(FLAGS)  -c BigInt.cpp

test.o : test.cpp BigInt.h
	$(CC) $(FLAGS)  -c test.cpp
test: BigInt.o test.cpp
	$(CC) $(FLAGS) test.cpp -c
	$(CC) $(FLAGS) test.o BigInt.o -o test
	./test
clean:
	rm -rf *.o big test
