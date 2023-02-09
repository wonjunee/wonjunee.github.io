


#include <iostream>
#include <vector>

void print(const vector<int> v1)
{
	for (int i=0; i<v1.size(); i++)
		cout << v1[i] << " ";
	cout << endl;
}

int main()
{
	vector <int> numbers;
	numbers.push_back(10);
	numbers.push_back(20);
	numbers.push_back(30);

	print(numbers);
	numbers.pop_back();
	print(numbers);

	vector <int> myvector(5,10);
	for (int i=1; i<10; i++)
		myvector.push_back(i);

	print(myvector);
}