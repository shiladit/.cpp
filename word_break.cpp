#include <iostream>
#include <set>
using namespace std;

set <string> dict; // Global Dictionary

/* Idea is to partition the string, such that
the left hand partition is present in the dictionary.
If at any point we reach end of string, means we
have successfully partitioned the string into segments which
are contained in the dictionary and we return true */

bool word_break(string s, int pos)
{
	int n = s.length();

	/* If we have matched the entire string, return true */
	if(n == pos)
		return true;

	/* Partition the string at every position and check if
	its part of the dictionary, and continue from there on
	with the result of the string */
	for(int i=pos;i<n;i++)
	{
		string temp = s.substr(pos,i-pos+1);

		if(dict.find(temp) != dict.end()) // found match in dictionary
		{
			/* if a match happens, it means the string till this point
			is made up of words from the dict. So we add the string to
			this point into the set */
			dict.insert(s.substr(0,i+1));
			return word_break(s,i+1);
		}
	}

	/* No match found, return false */
	return false;
}

int main()
{
	string s;
	cin >> s;

	int n;
	cin >> n;

	for(int i=0;i<n;i++)
	{
		string temp;
		cin >> temp;
		dict.insert(temp);
	}

	if(word_break(s,0))
		cout << "True\n";
	else
		cout << "False\n";

	return 0;
}


/* SAMPLE TEST CASES */

/*
mypenmy
2
my
pen
*/