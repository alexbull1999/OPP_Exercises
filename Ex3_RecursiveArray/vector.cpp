#include <iostream>
#include "vector.h"

using namespace std;


Vector2::Vector2(double _xcoord, double _ycoord) : xcoord(_xcoord), ycoord(_ycoord) {};

ostream& operator << (ostream& output, const Vector2& v) {
	output << "(" << v.xcoord << "," << v.ycoord << ")" << endl;
	return output;
}


/* Alternative notation - can take multiple args if defined as a non-member function 
 * But requires the friend declaration */
Vector2 operator+(Vector2 a, Vector2 b) {
	return Vector2(a.xcoord + b.xcoord, a.ycoord + b.ycoord);
}

Vector2 operator*(double a, Vector2 b) {
	return Vector2(a*b.xcoord, a*b.ycoord);
}

Vector2 operator*(Vector2 a, double b) {
	return Vector2(a.xcoord*b, a.ycoord*b);
}


