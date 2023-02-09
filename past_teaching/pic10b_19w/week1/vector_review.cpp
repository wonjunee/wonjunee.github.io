#include<iostream>
#include<vector>
#include <math.h> 

using namespace std;


void print_vector(vector<int> v)
{
	for(int i=0; i<v.size(); ++i)
	{
		cout << v[i] << " ";
	}
}

// ------------------- Method 1 ------------------- 
void remove_duplicates(vector<int> & v)
{
	vector<int> vec_without_duplicates;
	
	for(int i=0; i<v.size(); ++i)
	{
		bool pushback = true;
		for(int j=0; j<vec_without_duplicates.size(); ++j)
		{
			if(v[i] == vec_without_duplicates[j])
			{
				pushback = false;
				break;
			}
		}
		if(pushback)
		{
			vec_without_duplicates.push_back(v[i]);
		}
	}
	v = vec_without_duplicates;
}


// ------------------- Method 2 ------------------- 
/* 
void remove_duplicates(vector<int> & v)
{
	for(int i=0; i<v.size(); i++)
	{
		for(int j=i+1; j<v.size(); j++)
		{
			if (v[i] == v[j])
			{
				v.erase(v.begin()+j);
				j--;
			}
		}
	}
}
*/

int main()
{
	while(true)
	{
		char yesorno;
		char ch = ' ';

		cout<<"Type the first set of numbers: ";

		vector<int> vec;
		do
		{
			int x;
			cin >> x;
			ch = cin.get();
			vec.push_back(x);
			
		} while (ch != '\n');

		remove_duplicates(vec);

		print_vector(vec);

	    cout << "\ncontinue? (y/n):";
	    cin >> yesorno;
	    if (yesorno == 'n')
	    {
	    	return 0;
	    }
	}
	return 0;
}
