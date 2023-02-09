#include<iostream>

using namespace std;

class Vector
{
public:
	Vector();
	Vector(double a, double b);

	double dot(const Vector& b);

	void operator+=(const Vector& b);
	void operator-=(const Vector& b);

	bool operator>(const Vector& b);
	bool operator<(const Vector& b);

	void print();

private:
	double xpos;
	double ypos;
};

Vector::Vector()
{
	xpos = 0;
	ypos = 0;
}

Vector::Vector(double a, double b)
{
	// TODO
	// Finish the code
	xpos = a;
	ypos = b;

}

double Vector::dot(const Vector& b)
{
	// TODO
	// Finish the code
	return xpos * b.xpos + ypos * b.ypos;
}

void Vector::operator+=(const Vector &b)
{
	xpos += b.xpos;
	ypos += b.ypos;
}

void Vector::operator-=(const Vector &b)
{
	// TODO
	// Finish the code
	xpos -= b.xpos;
	ypos -= b.ypos;
}

bool Vector::operator>(const Vector& b)
{
	// TODO
	// Finish the code

	return xpos*ypos > b.xpos*b.ypos;
}

bool Vector::operator<(const Vector& b)
{
	// TODO
	// Finish the code
	return xpos*ypos < b.xpos*b.ypos;
}

void Vector::print()
{
	cout << "[" << xpos << ", " << ypos << "]" <<endl;
};



int main()
{
	Vector v1 = Vector(2,3);
	Vector v2 = Vector(3,4);
	Vector v3 = Vector(1,5);

	cout << "v1:";
	v1.print();
	cout << "v2:";
	v2.print();
	cout << "v3:";
	v3.print();

	cout << "\nAfter v1 += v2" << endl;
	v1 += v2;

	cout << "v1:";
	v1.print();
	cout << "v2:";
	v2.print();
	cout << "v3:";
	v3.print();

	cout << "\nAfter v2 -= v3" << endl;
	v2 -= v3;

	cout << "v1:";
	v1.print();
	cout << "v2:";
	v2.print();
	cout << "v3:";
	v3.print();

	cout << "\nv1 dot v2 = " << v1.dot(v2) << endl;

	cout << "\nv1 > v2 = " << (v1 > v2) << endl;
	cout << "v1 < v2 = " << (v1 < v2) << endl;
}