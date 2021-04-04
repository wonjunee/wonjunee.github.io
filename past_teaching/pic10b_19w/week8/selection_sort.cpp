#include <iostream>
#include "util.h"

int min_position(vector<int>& a, int from, int to)
{
	int min_pos = from;
	for (int i=from + 1; i <= to; i++)
	{
		if (a[i] < a[min_pos]) min_pos = i;
	}
	return min_pos;
}

void selection_sort(vector<int>& a)
{
	for(int next = 0; next<a.size() - 1; next++)
	{
		int min_pos = min_position(a, next, a.size() -1);
		if(min_pos != next)
		{
			swap(a[min_pos], a[next]);
		}
	}
}

int main()
{
	rand_seed();
	vector<int> v(20);
	for(int i=0; i<v.size(); i++)
	{
		v[i] = rand_int(1,100);
	}
	print(v);
	selection_sort(v);
	print(v);
	return 0;
}