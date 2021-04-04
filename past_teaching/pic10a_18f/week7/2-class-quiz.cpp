/*
Exercise P5.4
*/

#include<iostream>
#include<iomanip>

using namespace std;

class Account
{
	// TODO Finish the code
	// Put your class here	
}


int main()
{
	// setup the account
	Account myAccount = Account();

	while(true)
	{
		cout << "1. Add money" << endl;
		cout << "2. Withdraw money" << endl;
		cout << "3. View the current balance" << endl;
		cout << "Q. Quit";

		int choice;
		cin >> choice;

		if (cin.fail())
		{
			cout << "GOOD BYE" << endl;
			break;	
		}
		
		// TODO Finish the code
	}
}
