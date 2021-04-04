/*
Exercise P4.3

Write a procedure sort3(int& a, int& b, int& c) that swaps its three

inputs to arrange them in sorted order.
*/


#include <iostream>

using namespace std;

void sort2(int& a, int& b)
{
	if (a> b)
	{
		int tmp =a;
		a= b;
		b = tmp;
	}
}

void sort3(int& a, int&b, int&c)
{
	sort2(a,c);
	sort2(a,b);
	sort2(b,c);
}

int main()
{
	int u = 3;
	int v = 4;
	int x = 1;

	sort3(u, v, x); // u is now 1, v is now 3, x is now 4
}