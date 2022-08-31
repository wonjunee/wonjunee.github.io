/*
Exercise P4.2. Write a procedure 

void sort2(int& a, int& b) 

that swaps  the values of a and b if a is greater than b 
and otherwise leaves a and b unchanged. 
*/

#include<iostream>

using namespace std;

void sort2(int& a, int& b)
{
	// TODO
	// Finish the code

	if(a>b)
	{
		int tmp = b;
		b = a;
		a = tmp;
	}

}

int main()
{
	int u = 2; 
	int v = 3; 
	int w = 4; 
	int x = 1; 
	sort2(u, v); // u is still 2, v is still 3 
	sort2(w, x); // w is now 1, x is now 4

	cout << "u is " << u <<endl;
	cout << "v is " << v <<endl;
	cout << "w is " << w <<endl;
	cout << "x is " << x <<endl;
}