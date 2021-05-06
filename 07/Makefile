CC=g++
FLAGS= -std=c++17 -Werror -fsanitize=address

all: test.o
test.o:
	$(CC) $(FLAGS) test.cpp -c
test: test.o
	$(CC) $(FLAGS) test.o -o test
	./test

clean:
	rm -rf *.o test
