#include <iostream>
#include "stack.h"

using namespace std;

int main() {

	Stack stack1;

	cout << stack1.count() << endl;
	
	stack1.push('a');
	stack1.push('l');
	stack1.push('e');
	stack1.push('x');
	stack1.push('b');
	cout << stack1 << endl;

	stack1.pop();

	cout << stack1 << endl;

	cout << "======================" << endl;


	for (int i = 0; i < stack1.count(); i++) {
		cout << "index " << i << ": " << stack1[i] << endl;
	}


	cout << "=========================" << endl;

	print_backwards("hello");
	print_backwards("I am a C++ God");


	return 0;

}
