
all: big
	./big
big: BigInt.o test.o
		g++  BigInt.o test.o -o big

BigInt.o : BigInt.cpp BigInt.h
	g++ -c BigInt.cpp

test.o : test.cpp BigInt.h
	g++ -c test.cpp

clean :
	rm -rf *.o big
