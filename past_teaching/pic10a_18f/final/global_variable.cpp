
#include<iostream>

using namespace std;

int a=5;
int b=3;

int fun(int b, int& c)
{
	a = b + c;
	b++;
	return b + ++c;
}

int main()
{
	int c;
	{
		int a = 10;
		int b = 20;
		c = fun(a,b);
		cout << a << b<< c << endl;
	}
	fun(c,a);
	cout << a << b << c;
}