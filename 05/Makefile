all: serializer
	./serializer

serializer: Serializer.o test.o
		g++ -o serializer Serializer.o test.o

Serializer.o : Serializer.cpp Serializer.h
	g++ -c Serializer.cpp

test.o: test.cpp Serializer.h serializer
	g++ -c test.cpp

clean:
	rm -rf *.o serializer
