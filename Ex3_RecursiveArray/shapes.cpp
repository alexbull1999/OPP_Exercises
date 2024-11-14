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

void Circle::callPrintCircle() {

	/* This needs to create an array of fixed length of circle objects to pass into printCircle();*/

	int times;
	cout << "How many consecutive circles would you like to print: ";
	cin >> times;
	int diameter_array[times];
	
	for (int count = 0; count < times; count++) {
		int diameter;
		cout << "Choose the diameter (height) of circle " << count + 1 << ": ";
		cin >> diameter;
		diameter_array[count] = diameter;
	}

	printCircle(diameter_array, times);
}

void Circle::printCircle(int* array, int size) {

	int heightbuffer = 5; //give a buffer of 5
	int maxwidth = 0;

	for (int count = 0; count < size; count++) {
		if (array[count] > maxwidth) {
			maxwidth = array[count]; 
		}
	}
	maxwidth = maxwidth + 10; //add buffer onto what was the largest diameter circle

	//construct vector to represent circle centre in middle of block to be printed
	
	for (int count = 0; count < size; count++)
	{
		int lineheight = heightbuffer*2 + (array[count]);
		Vector2 centre((lineheight/2), (maxwidth/2.0));
		Circle printc1(&centre, (array[count] / 2));

		//print operation:
		////traverse through rows
		for (int row=1; row < lineheight; row++) {
			for (int column=1; column < maxwidth; column++) {
				if (!printc1.isInside(row, column) && column != maxwidth-1) {
					cout << "**"; //print two characters each time as terminal fonts 2x tall as wide
				}
				else if (!printc1.isInside(row, column) && column == maxwidth-1) {
					cout << "**" << "\n";
				}
				else if (printc1.isInside(row, column) && column == maxwidth-1) {
					cout << "  " << "\n";
				}
				else if (printc1.isInside(row,column) && column != maxwidth-1) {
					cout << "  ";
				}
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



