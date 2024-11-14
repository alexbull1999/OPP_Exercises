execute: main.o shapes.o vector.o
	g++ -g -Wall main.o shapes.o vector.o -o execute

main.o: main.cpp shapes.h vector.h
	g++ -g -Wall -c main.cpp

vector.o: vector.cpp vector.h
	g++ -g -Wall -c vector.cpp

shapes.o: shapes.cpp shapes.h vector.h
	g++ -g -Wall -c shapes.cpp

clean:
	rm -f *.o execute
