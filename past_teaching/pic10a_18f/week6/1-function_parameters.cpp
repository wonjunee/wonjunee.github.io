/*
Quiz Functions with parameters
*/
#include<iostream>

using namespace std;

// TODO: write down function for multiply the value by 2
int multiplyby2(int m)
{
	return m * 2;
}

int main()
{

    int m1 = 4;

    m1 = multiplyby2(m1);

    cout << "m1 is " << m1 << endl;

    return 0;
}

