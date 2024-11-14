nclude<iostream>
#include<cmath>

using namespace std;

class Vector2 {

	public:
		Vector2(float x, float y);

		float get_x() const;
		float get_y() const;

		void add(const Vector2 &other);

		float get_length() const;

		friend Vector2 operator+(const Vector2 &a, const Vector2 &b);
		friend Vector2 operator-(const Vector2 &a, const Vector2 &b); //overloads the minus operator
		friend Vector2 operator*(float f, const Vector2 &v);
		friend Vector2 operator*(const Vector2 &v, float f);

		friend std::ostream& operator<<(std::ostream& os, const Vector2 &v);

	private:
		float x, y;

};

Vector2::Vector2(float x, float y) : x(x), y(y) { }

float Vector2::get_x() const {
	return x;
}

float Vector2::get_y() const {
	return y;
}

float Vector2::get_length() const {
	return sqrt(x*x + y*y);
}

void Vector2::add(const Vector2 &other) {
	x += other.x;
	y += other.y;
}

Vector2 operator+(const Vector2 &a, const Vector2 &b) {
	return Vector2(a.x + b.x, a.y + b.y);
}

Vector2 operator-(const Vector2 &a, const Vector2 &b) {
	return Vector2(a.x - b.x, a.y - b.y);
}

Vector2 operator*(float f, const Vector2 &v) {
	return Vector2(f * v.x, f * v.y);
}
Vector2 operator*(const Vector2 &v, float f) {
	return f * v;
}

std::ostream& operator<<(std::ostream& os, const Vector2 &v) {
	cout << "(" << v.x << "," << v.y << ")";
	return os;
}


const float PI = 3.1415;

class Circle {

	public:
		Circle(Vector2 position, float radius);

		Vector2 get_position() const;
		float get_radius() const;

		float calculate_area() const;

		bool isInside(float x, float y) const;

	private:
		Vector2 position;
		float radius;

};

Circle::Circle(Vector2 position, float radius) : position(position), radius(radius) { }

Vector2 Circle::get_position() const {
	return position;
}

float Circle::get_radius() const {
	return radius;
}

float Circle::calculate_area() const {
	return PI * radius * radius;
}

bool Circle::isInside(float x, float y) const {
	return (position - Vector2(x, y)).get_length() <= radius;
} //subtracting two vectors here, and usign get_length function

//declared as a global function, not a member function
void print_circle(const Circle &c, int width = 80, int height = 40) {
	for (int y = height - 1; y >= 0; y--) {
			for (int x = 0; x < width; x++) {
						if (c.isInside(x, y)) {
										cout << " ";
									}
						else {
										cout << "*";
									}
									// cout << " "; // This will make the result more proportionate!
						}
						cout << endl;
	}
}
						
bool inside_any(Circle circles[], int count, float x, float y) {
	for (int c = 0; c < count; c++) {
		if (circles[c].isInside(x, y)) {
			return true;
		}
	}
	return false;
}

void print_circles(Circle circles[], int count, int width = 80, int height = 40) {
	for (int y = height - 1; y >= 0; y--) {
		for (int x = 0; x < width; x++) {
			if (inside_any(circles, count, x, y)) {
				cout << " ";
			}
			else {
				cout << "*";
			}
			// cout << " "; // This will make the result more proportionate!
		}
		cout << endl;
	}
}
						
						
int main() {
	Circle c(Vector2(15, 15), 10);
	print_circle(c);
	cout << endl;
	
	/*
	Circle circles[] = { Circle(Vector2(40, 16), 15), Circle(Vector2(25, 30), 7.5), Circle(Vector2(55, 30), 7.5)  };
	print_circles(circles, 3);*/

	return 0;


}
