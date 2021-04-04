#include <iostream>

using namespace std;


void hanoi(int from, int to, int n)
{
	int newfrom=0;
	int newto;

	if((from == 0 && to == 1) || (from == 1 && to == 0))
	{
		newto = 2;
	}
	if((from == 1 && to == 2) || (from == 2 && to == 1))
	{
		newto = 0;
	}
	if((from == 0 && to == 2) || (from == 2 && to == 0))
	{
		newto = 1;
	}

	if(n<=1)
	{
		cout << "Move disk from peg " << from << " to peg " << to << endl;
		return;
	}
	
	
	hanoi(from, newto, n-1);
	cout << "Move disk from peg " << from << " to peg " << to << endl;
	hanoi(newto, to, n-1);
}

void play(int n)
{
	return hanoi(0,2,n);
}

int main()
{
	play(5);
}

