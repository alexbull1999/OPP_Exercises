#ifndef STACK_H
#define STACK_H

#define MAX_SIZE 100

#include <iostream>

using namespace std;

class Stack {

	public:
		Stack(); //default constructor
		
		int count() const;

		void push(char value);
		char pop();

		friend ostream& operator<< (ostream& output, const Stack stack);

		//operates on non-const instances of Stack class
		char& operator[](int index); 

		//operates on const instances of Stack class
		const char& operator[](int index) const;

	private:
		char array[MAX_SIZE];
		int head;


};

void print_backwards(const char* string);

#endif
