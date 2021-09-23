// Leetcode
#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;

/* stores palindromes */
set <string> st;

bool isPalindrome(string s, int l, int r)
{
	while(l < r)
	{
		if(s[l] != s[r])
			return false;

		l++;
		r--;
	}

	/* it is a palindrome and we store it */
	st.insert(s.substr(l,r-l+1));
	return true;
}

void palindrome_partition(string s, int start, vector <string> &tmp, vector < vector <string> > &result)
{
	/* if we have reached end of string,
	then all the calls/partitions leading
	upto this are all palindromes and we
	store it in the final result */
	if(start == s.length())
	{
		result.push_back(tmp);
	}

	for(int i=start;i<s.length();i++)
	{
		/* if the substring is already encountered and found to be a palindrome
		or we checked and found it to be a palindrome, we store the left hand side
		of the partition in a temporary vector and continue processing the right hand
		side of the parition */
		if(st.find(s.substr(start,i-start+1)) != st.end() || isPalindrome(s,start,i))
		{
			tmp.push_back(s.substr(start,i-start+1));
			palindrome_partition(s,i+1,tmp,result);
			/* we backtrack and start looking for other solutions */
			tmp.pop_back();
		}
	}
}

vector < vector <string> > partition(string s)
{
	vector < vector <string> > result;
	vector <string> tmp;

	palindrome_partition(s,0,tmp,result);

	return result;
}

int main()
{
	string s;
	cin >> s;

	vector < vector <string> > result = partition(s);

	/* o/p */
	for(int i=0;i<result.size();i++)
	{
		for(int j=0;j<result[i].size();j++)
		{
			cout << result[i][j] << "," ;
		}
		cout << endl;
	}

	return 0;
}
