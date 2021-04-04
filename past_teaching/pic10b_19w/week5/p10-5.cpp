#include <iostream>

using namespace std;

bool find(string word, string target) 
{
	if(word.length() < target.length())
	{
		return false;
	}
	if(word.substr(0,target.length()) == target)
	{
		return true;
	}
	
	return find(word.substr(1), target);
}

int main()
{
	bool b = find("Mississippi!", "ssi"); // Returns true

	cout << b << endl;
}

