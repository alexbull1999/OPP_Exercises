#include <iostream>
#include <cmath>

using namespace std;

double pi = 3.14159265359; 

class Circle {
	public:
		Circle(int _centre[2], int _radius) : centre(_centre), xcoord(_centre[0]), 
		ycoord(_centre[1]), radius(_radius) {};
		Circle(int _xcoord, int _ycoord, int _radius) : centre(nullptr), 
		xcoord(_xcoord), ycoord(_ycoord), radius(_radius) {};

		void get_centre(int centre[]) {
			centre[0] = this->xcoord;
			centre[1] = this->ycoord;
		}

		int get_radius() {
			return this->radius;
		} 


		double calculate_area() {
			double area = pi*pow(radius, 2);
			return area;			
		}

		friend std::ostream& operator << (std::ostream& output, Circle& c)  {
			output << "centre is (" << c.xcoord << ", " << c.ycoord << ")"
				<< " and radius is " << c.radius << endl;
			return output;
		}

	private: 
		int* centre;
		int xcoord;
		int ycoord;
		int radius;


};

class Rectangle {
	public:
		Rectangle(int _LHCorner[2], int _width, int _height) : LHCorner(_LHCorner), 
		xcoord(_LHCorner[0]), ycoord(_LHCorner[1]), width(_width), height(_height) {};

		Rectangle(int _xcoord, int _ycoord, int _width, int _height) : LHCorner(nullptr),
		xcoord(_xcoord), ycoord(_ycoord), width(_width), height(_height) {};
		
		void get_centre(int centre[]) {
			centre[0] = this->xcoord;
			centre[1] = this->ycoord;
		}

		int get_height() {
			return this->height;
		}

		int get_width() {
			return this->width;
		}

		int calculate_area() {
			int area = height*width;
			return area;
		}

		friend std::ostream& operator << (std::ostream& output, Rectangle& r) {
			output << "left hand corner is (" << r.xcoord << ", " << r.ycoord << ")"
				<< " and width is " << r.width << " and height is " << r.height << endl;
			return output;
		}

	private:
		int* LHCorner;
		int xcoord;
		int ycoord;
		int width;
		int height;
};


int main() {

	int circle1centre[] = {5, 5};
	int circle2centre[] = {10, 10};
	Circle circle1 = Circle(circle1centre, 10);
	Circle circle2 = Circle(circle2centre, 20);
	Circle circle3 = Circle(30, 30, 50);
	double area1 = circle1.calculate_area();
	double area2 = circle2.calculate_area();
	double area3 = circle3.calculate_area();

	cout << "Circle1 " << circle1 << " and area of circle 1 is " << area1 << endl;
	cout << "Circle2 " << circle2 << " and area of circle 2 is " << area2 << endl;
	cout << "Circle3 " << circle3 << " and area of circle 3 is " << area3 << endl;

	cout << "Circle1 radius is " << circle1.get_radius() << endl;
	int checkcirclecentre[2];
	circle1.get_centre(checkcirclecentre);
	cout << "Circle1 centre is: (" << checkcirclecentre[0] << "," << checkcirclecentre[1] << ")" << endl;


	int rectangle2corner[] = {9, 9};
	Rectangle rectangle1 = Rectangle(2, 3, 5, 15);
	Rectangle rectangle2 = Rectangle(rectangle2corner, 9, 9);
	int rarea1 = rectangle1.calculate_area();
	int rarea2 = rectangle2.calculate_area();

	cout << "Rectangle1 " << rectangle1 << " and area of rectangle 1 is " << rarea1 << endl;
	cout << "Rectangle2 " << rectangle2 << " and area of rectangle 2 is " << rarea2 << endl;

	cout << "Rectangle1 height is: "<< rectangle1.get_height() << endl;
	cout << "Rectangle1 width is: " << rectangle1.get_width() << endl;
	int checkcentre[2];
	rectangle1.get_centre(checkcentre);
	cout << "Rectangle1 corner is: (" << checkcentre[0] << ", " << checkcentre[1] << ")" << endl;


return 0;

}
