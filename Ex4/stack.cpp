#include <iostream>
#include "stack.h"

using namespace std;

Stack::Stack() : head(0) {};

int Stack::count() const {
	return head;
}

void Stack::push(char value) {
	if(head == MAX_SIZE) { exit(1); }
	array[head] = value;
	head++;
}

char Stack::pop() {
	if (head == 0) { exit(1); }
	head--;
	char end = array[head];
	array[head] = '\0';
	return end;
}

ostream& operator<< (ostream& output, const Stack stack) {
	for (int count = 0; count <= stack.head; count++) {
		output << stack.array[count];
	}
	return output;
} 

char& Stack::operator[](int index) {
	return array[index];
}

const char& Stack::operator[](int index) const {
	return array[index];
}

void print_backwards(const char* string) {
	Stack strstack;

	while (*string != '\0') //should hit sentinel character and become null
	{
		strstack.push(*string); //dereference ptr
		string++;			
	}

	cout << "Your string forwards is: " << strstack << endl;

	cout << "Your string backwards is: ";
	while (strstack.count() > 0) {
		cout << strstack.pop();
	}
	
	/*
	for (int counter = strstack.count() - 1; counter >= 0; counter--) {
		cout << strstack[counter];
	}
	*/

	cout << "\n";

}


