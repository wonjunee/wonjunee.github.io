#include<iostream>
#include<vector>

using namespace std;


double scalar_product(vector<double> a, vector<double> b)
{
	double sum = 0;
	for(int i=0; i<a.size(); ++i)
	{
		sum += a[i] * b[i];
	}
	return sum;
}

int main()
{
	vector< int > a;
	vector< int > b;
	a.push_back(1);
	a.push_back(2);
	a.push_back(3);

	b.push_back(2);
	b.push_back(3);
	b.push_back(1);

	cout << "sum is " << scalar_product(a,b) << endl;

}