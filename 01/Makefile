CC=g++
FLAGS= -std=c++17 -Werror -Wall -fsanitize=address

all: main.o allocator.o
	$(CC) $(FLAGS) main.o allocator.o -o main
main.o: main.cpp
	$(CC) $(FLAGS) main.cpp -c
allocator.o: allocator.hpp allocator.cpp
	$(CC) $(FLAGS) allocator.cpp -c  

clean:
	rm -f *.o main test
test: main.o allocator.o test.cpp
	$(CC) $(FLAGS) test.cpp -c
	$(CC) $(FLAGS) test.o allocator.o -o test
	./test
