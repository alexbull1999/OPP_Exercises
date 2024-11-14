#include <iostream>
#include <cmath>
#include "shapes.h"
#include "vector.h"

using namespace std;

Circle::Circle(Vector2* _centre, double _radius) : centre(_centre), radius(_radius) {}


double Circle::calculate_area() {
	double area = pi*pow(radius, 2);
	return area;			
}

bool Circle::isInside(double x, double y) {
	//length of the line from centre to x,y < radius then inside
	//x-length = x-Vector2x //same for y length
	double xlength = x - centre->getXcoord();
	double ylength = y - centre->getYcoord();
	double newline = sqrt(pow(xlength, 2) + pow(ylength, 2));
	if (newline > radius) {
		//cout << "point (" << x << "," << y << ") is outside the circle where the " << *this;
		return false;
	}
	else if (newline == radius) {
		//cout << "point (" << x << "," << y << ") is on the circle where the " << *this;
		return true;
	}
	//cout << "point (" << x << "," << y << ") is inside the circle where the " << *this;
	return true;
}

void Circle::printCircle() {

	double lineheight;
	double linewidth;
	double diameter;
	cout << "Choose the total number of lines you want to print (height), containing your circle: ";
	cin >> lineheight;
	linewidth = lineheight; 
	cout << "Choose the diameter (height) of the circle you want to print: ";
	cin >> diameter;
	double rad = diameter/2.0;

	//construct vector to represent circle centre in middle of block to be printed
	Vector2 c_centre((lineheight/2.0), (linewidth/2.0));
	cout << c_centre;
	//We might need to call the above using Vector2 namespace?
	Circle printc1(&c_centre, rad);
	cout << printc1;

	//print operation:
	////traverse through rows
	for (int row=1; row < lineheight; row++) {
		for (int column=1; column < linewidth; column++) {
			if (!printc1.isInside(row, column) && column != linewidth-1) {
				cout << "**"; //print two characters each time as terminal fonts 2x tall as wide
			}
			else if (!printc1.isInside(row, column) && column == linewidth-1) {
				cout << "**" << "\n";
			}
			else if (printc1.isInside(row, column) && column == linewidth-1) {
				cout << "  " << "\n";
			}
			else if (printc1.isInside(row,column) && column != linewidth-1) {
				cout << "  ";
			}
		}
	}

}

//to create an array of circles, can we call above function recursively, to then print multiple shapes?


ostream& operator << (std::ostream& output, Circle& c)  {
	output << "centre is (" << c.centre->getXcoord() << ", " << c.centre->getYcoord() << ")"
		<< " and radius is " << c.radius << endl;
	return output;
}



