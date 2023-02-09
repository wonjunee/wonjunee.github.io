/*
00000 0:5 1:0	i=0	j=5 k=0
00001 0:4 1:1	i=1 j=4 k=1
00011 0:3 1:2	i=2 j=3 k=2
00111 0:2 1:3	i=3 j=2
01111 0:1 1:4	i=4	j=1
11111 0:0 1:5	i=5	j=0
*/

#include<iostream>
using namespace std;

int main()
{
	for(int i=0; i<6; ++i)
	{
		for(int j=5; j>0; --j)
		{
			if(i<j)
			{
				cout << "0";
			}
			else
			{
				cout << "1";
			}
		}
		cout << endl;
	}
}