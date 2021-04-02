CC=g++
FLAGS= -std=c++17 -Werror -Wall -fsanitize=address -Wextra

all: test.o parser.o
	$(CC) $(FLAGS) test.o parser.o -o test
test.o: test.cpp
	$(CC) $(FLAGS) test.cpp -c
parser.o: parser.cpp
	$(CC) $(FLAGS) parser.cpp -c
lib:
	g++ -c parser.cpp
	g++ -c test.cpp
	ar rvs libparser.a parser.o
	g++ -o testlib test.o -L. -lparser
	./testlib
clean: parser.cpp
	rm -f *.o test testlib
