#include <iostream>

using namespace std;

int index_of(string word, string target) 
{
	if(word.length() < target.length())
	{
		return -1;
	}
	if(word.substr(0,target.length()) == target)
	{
		return 0;
	}
	
	return 1 + index_of(word.substr(1), target);
}

int main()
{
	int b = index_of("Mississippi!", "pi");

	cout << b << endl;
}

