#include<iostream>
#include<fstream>

using namespace std;
int main()
{
	ifstream asdf; // this will create an ifstream object
				   // that can open/read files from numbers.dat

	asdf.open("number.dat"); // loading numbers.dat

	int a1, a2, a3, a4, a5, a6, a7;

	asdf >> a1 >> a2 >> a3 >> a4 >> a5 >> a6 >> a7;

	cout << a1 << " ";
	cout << a2 << " ";
	cout << a3 << " ";
	cout << a4 << " ";
	cout << a5 << " ";
	cout << a6 << " ";

	asdf.close(); // always close after you are done.
}