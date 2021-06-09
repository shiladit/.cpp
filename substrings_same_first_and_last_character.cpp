#include <iostream>
#include <set>
#include <string>
using namespace std;

set <string> s1;

void print_substring(string s, int i, int len)
{
	string temp = s.substr(i,len);
	if(s1.find(temp) == s1.end())
	{
		cout << temp << endl;
		s1.insert(temp);
	}
}

void generate_substrings(string s, int start, int end)
{
	if(start > end)
		return;

	if(s[start] == s[end])
	{
		print_substring(s,start,(end-start)+1);
		return;
	}

	generate_substrings(s, start+1, end);
	generate_substrings(s, start, end-1);
	generate_substrings(s, start+1, end-1);

	return;
}

int main()
{
	string s;
	cin >> s;

	int n = s.length();
	assert(n>0);

	generate_substrings(s,0,n-1);

	return 0;
}
