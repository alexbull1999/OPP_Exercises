execute: main.o stack.o
	g++ -g -Wall main.o stack.o -o execute

main.o: main.cpp stack.h
	g++ -g -Wall -c main.cpp

stack.o: stack.cpp stack.h
	g++ -g -Wall -c stack.cpp

clean:
	rm -f *.o execute
