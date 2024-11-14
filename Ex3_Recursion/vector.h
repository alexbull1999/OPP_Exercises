#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>

class Vector2 {

	public: 
		Vector2(double _xcoord, double _ycoord);
		
		double getXcoord() {
			return this->xcoord;
		};
		
		double getYcoord() {
			return this->ycoord;
		};

		void add(const Vector2& v) {
			this->xcoord = this->xcoord + v.xcoord;
			this->ycoord = this->ycoord + v.ycoord;
		};


	/*	// Defining the plus operator as a member function (can only have 1 or 0 args)
		Vector2 operator + (const Vector2& operand)  {
			Vector2 result = Vector2((this->xcoord + operand.xcoord), (this->ycoord + operand.ycoord));
			return result;
		}; */

		friend std::ostream& operator << (std::ostream& output, const Vector2& v);

		friend Vector2 operator+(Vector2 a, Vector2 b);

		friend Vector2 operator*(double a, Vector2 b);
		friend Vector2 operator*(Vector2 a, double b); //note how multiple overloadings are possible with different parameters / different order to same parameters
	
	private:
		double xcoord;
		double ycoord;

};

#endif


