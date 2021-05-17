CC=g++
FLAGS= -std=c++17 -Werror -Wall -fsanitize=address

all: serializer

serializer: Serializer.o test.o
	$(CC) $(FLAGS) Serializer.o test.o -o serializer

Serializer.o: Serializer.cpp Serializer.h
	$(CC) $(FLAGS) Serializer.cpp -c 

test.o: test.cpp
	$(CC) $(FLAGS) test.cpp -c
	
test: test.o Serializer.o test.cpp Serializer.cpp Serializer.h
	$(CC) $(FLAGS) Serializer.o test.o  -o test
	./test

clean:
	rm -rf *.o serializer test
