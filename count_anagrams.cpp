#include <iostream>
#include <unordered_map>
using namespace std;

int count_anagrams(string str,string pattern)
{
	if(str.length() < pattern.length())
	{
		// Not possible
		return -1;
	}

	int result = 0;

	unordered_map <char,int> pat_map;
	unordered_map <char,int> str_map;

	/* initial frequency count of chars in both
	pattern and string for the first pattern.length()
	chars */
	for(int i=0;i<pattern.length();i++)
	{
		pat_map[pattern[i]]++;
		str_map[str[i]]++;
	}

	/* if hash map for both pattern and string is same */
	if(pat_map == str_map)
	{
		result++;
	}

	/* Sliding Window */
	for(int i=1;i<str.length()-pattern.length()+1;i++)
	{
		str_map[str[i-1]]--;
		str_map[str[i+pattern.length()-1]]++;

		if(pat_map == str_map)
			result++;
	}

	return result;
}

int main()
{
	string str = "aabaababaa";
	string pattern = "abaa";

	cout << count_anagrams(str,pattern) << endl;

	return 0;
}