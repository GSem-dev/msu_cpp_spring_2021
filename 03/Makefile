all: matrix

matrix : Matrix.o test.o
		g++ Matrix.o test.o -o matrix

Matrix.o : Matrix.cpp
	g++ -c Matrix.cpp

test.o : test.cpp
	g++ -c test.cpp

clean :
	rm -rf *.o matrix
