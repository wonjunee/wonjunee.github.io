#include <iostream>

using namespace std;

class Sentence
{
public:
	Sentence(string s_);
	void reverse();
	string get_text() const;
private:
	string s;
	string r_s;
};

Sentence::Sentence(string s_)
{
	s = s_;
}

string Sentence::get_text() const
{
	return r_s;
}

void Sentence::reverse()
{
	if(s.length() <= 1)
	{
		r_s = s;
		return;
	}

	Sentence small_s(s.substr(0,s.length()-1));
	small_s.reverse();

	r_s = s[s.length()-1] + small_s.get_text();
}

int main()
{
	Sentence greeting = Sentence("HELLOLLLO!"); 
	greeting.reverse(); 
	cout << greeting.get_text() << "\n";
}