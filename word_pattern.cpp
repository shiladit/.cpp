#include <string>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

int main()
{
	string pattern;
	cin >> pattern;

	string s;
	cin >> s;

	string word;
	vector <string> arr;

	istreamstring words(s);

	while(words >> word)
	{
		arr.push_back(word);
	}

	return 0;
}

