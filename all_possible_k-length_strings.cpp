#include <iostream>
#include <vector>
#include <string>
using namespace std;

/* Given a dictionary and a value k, print all possible strings of length k */


/* dictionary */
vector <char> dict;

void printstrings(int index, int k, string temp)
{
	/* Keep adding characters to the temp string,
	when index reaches k, print out the temp string
	as length has reached k */

	if(index == k)
	{
		cout << temp << endl;
		return;
	}

	for(int i=0;i<dict.size();i++)
	{
		printstrings(index+1,k,temp + dict[i]);
	}

	return;
}

int main()
{
	dict.push_back('a');
	dict.push_back('b');
	dict.push_back('c');

	int k; cin >> k;
	printstrings(0,k,"");

	return 0;
}