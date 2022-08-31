#include <iostream>
#include <fstream>
#include <time.h>
#include "util.h"

void merge(vector<int>& a, int from, int mid, int to) {

	int n = to - from + 1; // Size of the range to be merged // Merge both halves into a temporary vector b

	vector<int> b(n);

	int i1 = from; // Next element to consider in the ﬁrst half

	int i2 = mid + 1; // Next element to consider in the second half 

	int j = 0; // Next open position in b

	while (i1 <= mid && i2 <= to) 
	{
		if (a[i1] < a[i2]) 
		{
			b[j] = a[i1];
			i1++; 
		} 
		else 
		{
			b[j] = a[i2];
			i2++; 
		} 

		j++;
	}

	// Note that only one of the two while loops below is executed

	// Copy any remaining entries of the ﬁrst half 
	while (i1 <= mid)
	{
		b[j] = a[i1]; i1++; j++;
	} 
	// Copy any remaining entries of the second half
	while (i2 <= to) 
	{
		b[j] = a[i2];
		i2++;
		j++; 
	}

	// Copy back from the temporary vector 
	for (j = 0; j < n; j++)
		a[from + j] = b[j];
}

void merge_sort(vector<int>& a, int from, int to) {
	if (from == to) return; 
	int mid = (from + to) / 2; 
	// Sort the ﬁrst and the second half 
	merge_sort(a, from, mid); 
	merge_sort(a, mid + 1, to); 
	merge(a, from, mid, to);
}


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

int main() {
	ofstream out;

	out.open("sort_data.dat");

	rand_seed(); 
	clock_t t;
	for(int N=1000; N<11000; N+=1000)
	{
		out << N << ",";
		vector<int> v_raw(N); 

		for (int i = 0; i < v_raw.size(); i++) 
			v_raw[i] = rand_int(1, 100); 
		
		vector<int> v = v_raw;
		print(v);
		t = clock();
		selection_sort(v); 
		t = clock() -t;
		out << t << ",";

		v = v_raw;
		print(v);
		t = clock();
		merge_sort(v, 0, v.size() - 1); 
		t = clock() -t;
		out << t << "\n";
	}
	out.close();
	
	return 0;

}