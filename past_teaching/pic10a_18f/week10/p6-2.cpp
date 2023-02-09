#include<iostream>
#include<vector>

using namespace std;


double alternating_sum(vector<double> a)
{
	double sum = 0;

	// 1
	for(int i=0; i < a.size(); ++i)
	{
		sum += (-1)**i * a[i];
	}
	return sum;

	// // 2
	// for(int i=0; i< a.size(); ++i)
	// {
	// 	if(i % 2 == 0) // when i is even
	// 	{
	// 		sum += a[i];
	// 	}
	// 	else // when i is odd
	// 	{
	// 		sum -= a[i];
	// 	}
	// }
	// return sum;

	// // 3
	// for (int i=0; i<a.size(); i+=2)
	// {
	// 	sum += a[i];
	// }
	// for (int i=1; i<a.size(); i+=2)
	// {
	// 	sum -= a[i];
	// }
	// return sum;
}

int main()
{
	vector< int > a;
	a.push_back(1);
	a.push_back(4);
	a.push_back(9);
	a.push_back(16);
	a.push_back(9);
	a.push_back(7);
	a.push_back(4);
	a.push_back(9);
	a.push_back(11);


	cout << "sum is " << alternating_sum(a) << endl;

}