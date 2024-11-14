#ifndef SHAPES_H
#define SHAPES_H

#include "vector.h"
#include <iostream>
#include <cmath>

const double pi = 3.14159265359; 

class Circle {
	public:
		Circle(Vector2* _centre, double _radius);

		Vector2* get_centre() {
			return this->centre;
		}

		int get_radius() {
			return this->radius;
		} 

		double calculate_area();

		bool isInside(double x, double y);

		static void callPrintCircle();

		static void printCircle(int* array, int size);

		friend std::ostream& operator << (std::ostream& output, Circle& c);

	private: 
		Vector2* centre;
		double radius;

};

#endif
