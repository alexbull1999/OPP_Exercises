#include <iostream>

using namespace std;

class Vector2 {

	public: 
		Vector2(double _xcoord, double _ycoord) : xcoord(_xcoord), ycoord(_ycoord) {};
		
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

		friend std::ostream& operator << (ostream& output, const Vector2& v) {
			output << "(" << v.xcoord << ", " << v.ycoord << ")" << endl;
			return output;
		};

		friend Vector2 operator+(Vector2 a, Vector2 b);

		friend Vector2 operator*(double a, Vector2 b);
		friend Vector2 operator*(Vector2 a, double b); //note how multiple overloadings are possible with different parameters / different order to same parameters
	
	private:
		double xcoord;
		double ycoord;

};

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


int main() {
	Vector2 first_vector = Vector2(10.0, 30.0);
	Vector2 second_vector = Vector2(15.0, 5.0);
	Vector2 result = first_vector + second_vector;
	first_vector.add(second_vector);
	cout << "Result is: " << result;
	cout << "First vector is now: " << first_vector;
	result = first_vector + second_vector;
	cout << "Result is now: " << result;
	first_vector.add(second_vector);
	cout << "First vector is now: " << first_vector;


	cout << "=======================\n";
	Vector2 v3(1, 2);
	Vector2 v4(3, 4);
	Vector2 v5 = v3 + v4;
	cout << v3;
	cout << v4;
	cout << v5;
	cout << "Vector (1,2) times 2.5 = " << v3 * 2.5;


	return 0;
}
