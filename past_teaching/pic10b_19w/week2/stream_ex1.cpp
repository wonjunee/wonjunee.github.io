#include <iostream>
#include <fstream>

using namespace std;

int main() 
{
	ifstream infile; 
	infile.open("numbers.txt"); 
	if (infile.fail()) 
	{
		cout << "Error opening " << "\n";
		return 1; 
	} 

	double next;
	
	// Reading the file
	while(infile >> next)
	{
		cout << next << ", ";
	}

	cout << "\n";

	infile.close(); 
	return 0;

}