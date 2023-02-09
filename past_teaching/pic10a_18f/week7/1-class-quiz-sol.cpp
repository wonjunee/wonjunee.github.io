/*
Exercise P5.1
*/

#include<iostream>
#include<iomanip>

using namespace std;

class Person
{
public:
	Person(); // constructor (default)
	Person(string pname, int page); // constructor
	void get_name() const; // accessor
	void get_age() const; // accessor
private:
	string name;
	int age;
};

Person::Person()
{
	name = "some default";
	age = 0;
}

Person::Person(string pname, int page)
{
	name = pname;
	age = page;
}

void Person::get_name() const
{
	cout << name;
}

void Person::get_age() const
{
	cout << age;
}


int main()
{
	Person person1 = Person("david", 13);
	cout << "Name: ";
	person1.get_name();
	cout << endl;

	cout << "Age:  ";
	person1.get_age();
	cout << endl;
}
