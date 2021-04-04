#include<iostream>
#include<vector>

using namespace std;

bool equals(vector<int> a, vector<int> b)
{
	if(a.size() != b.size())
	{
		return false;
	}

	for (int i=0; i<a.size(); ++i)
	{
		if(a[i] != b[i])
		{
			return false;
		}
	}
	return true;
}

int main()
{
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);

	vector<int> v2;
	v2.push_back(1);
	v2.push_back(2);
	v2.push_back(4);

	cout << equals(v1,v2);
}