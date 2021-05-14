CC=g++
FLAGS= -std=c++17 -std=c++17 -Werror -Wall -fsanitize=address

all: pool
	./test
pool: test.cpp pool.h
	$(CC) $(FLAGS) test.cpp -o test -lpthread

test: pool
	./test
clean:
	rm -rf *.o test
