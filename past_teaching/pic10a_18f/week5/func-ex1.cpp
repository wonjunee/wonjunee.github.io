/*
Exercise P4.1. Enhance the program computing bank balances in 
Section 4.2 by prompting for the initial balance and the interest 
tate. Then print the balance after 10, 20, and 30 years.
*/

#include <iostream>
#include <cmath>

using namespace std;

void printBalance(double initbalance, double rate)
{
	for (int i=10; i< 31; i+=10)
	{
		double balance = initbalance * pow(1+rate, i);
		cout << "balance after " << i << " years: " << balance << endl;
	}
}

int main()
{
	printBalance(1000,0.05);
}