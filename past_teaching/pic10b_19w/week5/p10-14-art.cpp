#include <iostream>
#include <vector>

using namespace std;

class Art
{
public:
	Art(int maxN_);
	void move(int from, int to);
	void hanoi(int from, int to, int n);
	void play();

	void display() const;
private:
	int maxN;
	vector<vector<int> > p;
};

Art::Art(int maxN_)
{
	maxN = maxN_;
	vector<int> a;
	for(int i=0; i<3; ++i)
	{
		p.push_back(a);
	}

	for(int i=0; i<maxN; ++i)
	{
		p[0].push_back(maxN-i);
	}
}

void Art::move(int from, int to)
{
	int a = p[from].back();

	p[from].pop_back();
	p[to].push_back(a);
}

void Art::display() const
{
	string str = "";
	for(int i=0; i<2*maxN+3; ++i)
	{
		str += "_";
	}
	str+="  ";

	cout << str << str << str << endl;

	for(int i=maxN-1; i>=0; --i)
	{
		string long_str;
		
		for(int j=0; j<3; ++j)
		{
			string str_temp = str;
			if(p[j].size() > i)
			{
				// cout<<"p j i " << p[j][i] << endl;
				for(int k=0; k<p[j][i]; ++k)
				{
					str_temp[k+maxN+1] = '$';
					str_temp[-k+maxN+1] = '$';
				}	
			}
			long_str += str_temp;
		}	
		cout << long_str << endl;
	}

	cout << "\n\n";
	
}

void Art::hanoi(int from, int to, int n)
{
	int newfrom=0;
	int newto;

	if((from == 0 && to == 1) || (from == 1 && to == 0))
	{
		newto = 2;
	}
	if((from == 1 && to == 2) || (from == 2 && to == 1))
	{
		newto = 0;
	}
	if((from == 0 && to == 2) || (from == 2 && to == 0))
	{
		newto = 1;
	}

	if(n<=1)
	{
		move(from, to);
		display();
		return;
	}
	
	hanoi(from, newto, n-1);
	move(from, to);
	display();
	hanoi(newto, to, n-1);
}

void Art::play()
{
	display();
	return hanoi(0,2,maxN);
}

int main()
{
	cout << "-------------------------------------------" << endl;
	cout << "		PLAYING HANOI" << endl;
	cout << "-------------------------------------------\n" << endl;
	cout << "How many pegs?: ";
	int n;
	cin >> n;
	Art art(n);
	art.play();
}

