CC=g++
FLAGS= --std=c++17 -Werror -Wall -fsanitize=address -Wextra

all: test.o parser.o
	$(CC) $(FLAGS) test.o parser.o -o test
test.o: test.cpp parser.o
	$(CC) $(FLAGS) test.cpp -c
	$(CC) $(FLAGS) parser.o test.o -o test
	./test
parser.o: parser.cpp parser.hpp
	$(CC) $(FLAGS) parser.cpp -c
test:
	$(CC) $(FLAGS) -c parser.cpp
	$(CC) $(FLAGS) -c test.cpp
	ar rvs libparser.a parser.o
	$(CC) $(FLAGS) -o testlib test.o -L. -lparser
	./testlib
clean: parser.cpp
	rm -f *.o test testlib
