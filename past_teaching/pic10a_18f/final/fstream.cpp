#include<iostream>
#include<fstream>

using namespace std;
int main()
{
	ifstream asdf; // this will create an ifstream object
				   // that can open/read files from numbers.dat

	asdf.open("words.dat"); // loading numbers.dat

	string s;

	while(true)
	{
		getline(asdf, s); // read a line from a file

		if(asdf.fail()) // check if it is the end of the file.
						// if it is, then asdf.fail() is true
		{
			break;
		}
		cout << s << endl;
	}

	asdf.close(); // always close after you are done.
}