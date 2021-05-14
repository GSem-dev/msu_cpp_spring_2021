CC=g++
FLAGS= -std=c++17 -Werror -Wall -fsanitize=address

all: pool
	./test
pool: test.o
	$(CC) $(FLAGS) test.o -o test

test.o: test.cpp pool.h
	$(CC) $(FLAGS) -c test.cpp

run: pool
	./test
clean:
	rm -rf *.o test
