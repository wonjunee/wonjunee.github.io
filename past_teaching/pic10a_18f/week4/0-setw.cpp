#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	string sample = "hello";

	cout << "|" << setw(10) << "hello"<< "|"<< endl;
	cout << "|" << setw(10) << "world!"<< "|"<< endl;
	cout << "|" << setw(10) << "WOWOWWOOO"<< "|"<< endl;
	cout << " \^\^\^\^\^\^\^\^\^\^ " << endl;
	cout << "10 characters\n" << endl;

	cout << "|" << setw(8) << "hello"<< "|" << endl;
	cout << " \^\^\^\^\^\^\^\^ " << endl;
	cout << "8 characters\n" << endl;


	// if setw(length) is less than the length of the string then
	// it will just print out hello
	cout << "|" << setw(1) << "hello"<< "|" << endl;
	cout << " \^\^\^\^\^ " << endl;
	cout << "5 characters\n" << endl;

	cout << "|" << setw(2) << "hello"<< "|" << endl;
	cout << " \^\^\^\^\^ " << endl;
	cout << "5 characters\n" << endl;

	cout << "|" << setw(3) << "hello"<< "|" << endl;
	cout << " \^\^\^\^\^ " << endl;
	cout << "5 characters\n" << endl;

	
}