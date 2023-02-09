#include<iostream>
#include "account.h"

using namespace std;

class Bank
{
public:
	void deposit(double amount, string account);
	void withdraw(double amount, string account);
	void transfer(double amount, string account);
	void print_balances();
private:
	Account account_checking;
	Account account_saving;
};

void Bank::deposit(double amount, string account)
{
	// TODO
}
void Bank::withdraw(double amount, string account)
{
	// TODO
}

void Bank::transfer(double amount, string account)
{
	// TODO
}

void Bank::print_balances()
{
	// TODO
}

/* 
DON'T MODIFY BELOW
*/
int main()
{
	Bank b1 = Bank();

	cout << "deposit" << endl;
	b1.deposit(1000,"C");
	b1.deposit(3000,"S");
	b1.print_balances();

	cout << "\nwithdraw" << endl;
	b1.withdraw(300,"C");
	b1.withdraw(1000,"S");
	b1.print_balances();

	cout << "\ntransfer" << endl;
	b1.transfer(50, "C");
	b1.print_balances();
}
