#include <iostream>
#include <fstream>

using namespace std;

/*
Note that the ifstream parameter of the read_data function is passed by reference. 
Reading from a ﬁle modiﬁes the ﬁle variable. 
The ﬁle variable monitors how many characters have been read or written so far. 
Any read or write operation changes that data. 
For that reason, you must always pass ﬁle variables by reference.
*/

double read_data(ifstream& in) { // <- Important

	double highest; 
	double next; 

	if (in >> next)
		highest = next; 
	else
		return 0;	

	while (in >> next) 
	{
		if (next > highest)
		highest = next; 
	} 

	return highest;

}

int main() 
{

	string filename; 
	cout << "Please enter the data file name: "; 
	cin >> filename; 
	ifstream infile; 
	infile.open(filename); 
	if (infile.fail()) 
	{
		cout << "Error opening " << filename << "\n";
		return 1; 
	} 

	double max = read_data(infile); 
	cout << "The maximum value is " << max << "\n"; 
	infile.close(); 
	return 0;

}