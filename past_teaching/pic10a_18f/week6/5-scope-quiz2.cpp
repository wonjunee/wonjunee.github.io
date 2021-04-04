/*
QUIZ

Expect the output
*/

#include <iostream>

using namespace std;

const double PI = 3.14;


double printsomething(double PI)
{
	cout << "3: " << PI << endl;

	PI = 11.3;

	cout << "4: " << PI << endl;

	return PI;
}

int main()
{
	cout << "1: " << PI << endl;

	double PI = -2;

	cout << "2: " << PI << endl;

	double a = printsomething(PI);

	cout << "5: " << PI << endl;	
}