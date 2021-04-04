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