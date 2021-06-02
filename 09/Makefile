CC=g++
FLAGS= -std=c++17 -Werror -fsanitize=address

all: test.o
test.o:
	$(CC) $(FLAGS) test.cpp -c
test: test.o sorte
	$(CC) $(FLAGS) test.o sort.o -o test
	./test

sorte:
	$(CC) $(FLAGS) sort.cpp -c
clean:
	rm -rf *.o test
