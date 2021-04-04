/*
Exercise P5.4
*/

#include<iostream>
#include<iomanip>

using namespace std;

class Account
{
public:
	Account(); // constructor (default)
	void add_money(double imoney); // mutator
	void withdraw_money(double imoney); // mutator
	double get_money() const; // accessor
private:
	double money;
};

Account::Account()
{
	money = 0;
}

void Account::add_money(double imoney)
{
	money += imoney;
}

void Account::withdraw_money(double imoney)
{
	money -= imoney;
}

double Account::get_money() const
{
	return money;
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
		cout << "Q. Quit" << endl;

		int choice;
		cin >> choice;

		if (cin.fail())
		{
			cout << "GOOD BYE" << endl;
			break;	
		}

		if (choice == 1)
		{
			double m;
			cin >> m;
			myAccount.add_money(m);
		}
		else if (choice == 2)
		{
			// withdraw money
			double m;
			cin >> m;
			myAccount.withdraw_money(m);
		}
		else if (choice == 3)
		{
			// view the current balance
			double your_current = myAccount.get_money();
			cout << " current balance: " << your_current << endl;
		}
	}
}
