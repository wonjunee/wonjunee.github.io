#include<iostream>
#include<vector>

using namespace std;

vector<int> merge(vector<int> a, vetor<int> b)
{
	vector<int> c;


	for(int i=0; i<min(a.size(), b.size()); ++i)
	{
		c.push_back(a[i]);
		c.push_back(b[i]);
	}

	if(a.size() <= b.size())
	{
		for(int i=a.size(); i<b.size(); ++i)
		{
			c.push_back(b[i]);
		}
	}
	else
	{
		for(int i=b.size(); i<a.size(); ++i)
		{
			c.push_back(a[i]);
		}
	}

	return c;
}