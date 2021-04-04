#include<iostream>
#include<fstream>
#include<vector>
#include<string>

using namespace std;

int main()
{
	ifstream infile;
	infile.open("database.txt");

	if(infile.fail())
	{
		cout << "FAIL" << endl;
		return 1;
	}

	string line;
	
	while(getline(infile, line))
	// whiel(infile >> line)
	{
		vector<string> lineVector;

		while(line.find("|")!=string::npos)
		{
			lineVector.push_back(line.substr(0, line.find("|")));

			line = line.substr(line.find("|")+1);
		}
		lineVector.push_back(line);

		ifstream tempfile;
		tempfile.open("template.txt");
		string words,word;
		string doc = "";

		while(getline(tempfile,words))
		{
			
			while(words.length() > 0)
			{
				bool add = true;
				if(words.find(" ")==string::npos)
				{
					word = words;
					words = "";
				}
				else
				{
					word = words.substr(0, words.find(" "));	
					words = words.substr(words.find(" ")+1);
				}
				
				for(int i=0; i<lineVector.size(); ++i)
				{
					if(word.substr(0,3) == "|" + to_string(i+1) + "|")
					{
						add = false;
						doc+= lineVector[i] + " ";	
						break;
					}
				}
				if(add)
				{
					doc+=word + " ";
				}
				
			}
			
			doc+="\n";
		}

		ofstream output;

		output.open("junk email to " + lineVector[1] + ".txt");

		output << doc;

		output.close();
	}

	infile.close();

}