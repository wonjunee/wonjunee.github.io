#include<iostream>
#include<vector>
#include <math.h> 

using namespace std;

void remove_duplicates(vector<int> & v)
{
	vector<int> tmp = v;
	vector<int> vec_without_duplicates;
	bool erase;
	while(tmp.size()>0)
	{
		erase = true;
		for(int i=0; i<vec_without_duplicates.size(); ++i)
		{
			if(tmp[0] == vec_without_duplicates[i])
			{
				tmp.erase(tmp.begin());
				erase = false;
				break;
			}
		}
		if(erase)
		{
			vec_without_duplicates.push_back(tmp[0]);	
		}
		
	}
	v = vec_without_duplicates;
	for(int i=0; i<v.size(); ++i)
	{
		cout << v[i] << " ";
	}

}

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

	    cout << "\ncontinue? (y/n):";
	    cin >> yesorno;
	    if (yesorno == 'n')
	    {
	    	return 0;
	    }
	}
	return 0;
}
