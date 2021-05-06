CC=g++
FLAGS= -std=c++17

all: matrix

test: matrix Matrix.o test.o
	./matrix

matrix: Matrix.o test.o
	$(CC) $(FLAGS) Matrix.o test.o -o matrix

Matrix.o: Matrix.cpp
	$(CC) $(FLAGS) -c Matrix.cpp

test.o: test.cpp
	$(CC) $(FLAGS) -c test.cpp

clean:
	rm -rf *.o matrix
