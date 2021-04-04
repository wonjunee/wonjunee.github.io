/*
QUIZ

Expect the output
*/

#include <iostream>

using namespace std;

const double PI = 3.14;


void printsomething()
{
	cout << "3: " << PI << endl;

	double PI = 11.3;

	cout << "4: " << PI << endl;
}

int main()
{
	cout << "1: " << PI << endl;

	double PI = -2;

	cout << "2: " << PI << endl;

	printsomething();

	cout << "5: " << PI << endl;	
}