// Leetcode
/* 
Simple and efficient iterative solution.

Explanation with sample input "123"

Initial state:

result = {""}
Stage 1 for number "1":

result has {""}
candiate is "abc"
generate three strings "" + "a", ""+"b", ""+"c" and put into tmp,
tmp = {"a", "b","c"}
swap result and tmp (swap does not take memory copy)
Now result has {"a", "b", "c"}
Stage 2 for number "2":

result has {"a", "b", "c"}
candidate is "def"
generate nine strings and put into tmp,
"a" + "d", "a"+"e", "a"+"f",
"b" + "d", "b"+"e", "b"+"f",
"c" + "d", "c"+"e", "c"+"f"
so tmp has {"ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf" }
swap result and tmp
Now result has {"ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf" }
*/

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

vector <string> letterCombinations(string digits)
{
	vector <string> result;

	if(digits.length() <= 0)
		return result;
	else
		result.push_back(""); // pushing blank string

	/* Build Map */
	unordered_map <int, string> umap;
	umap[2] = "abc";
	umap[3] = "def";
	umap[4] = "ghi";
	umap[5] = "jkl";
	umap[6] = "mno";
	umap[7] = "pqrs";
	umap[8] = "tuv";
	umap[9] = "wxyz";

	for(int i=0;i<digits.length();i++)
	{
		int digit = digits[i] - '0';
		string s = umap[digit];
		vector <string> tmp;

		for(int j=0;j<s.length();j++)
		{
			for(int x=0;x<result.size();x++)
			{
				tmp.push_back(result[x] + s[j]);
			}
		}

		result = tmp;
	}

	return result;
}

int main()
{
	string digits;
	cin >> digits;

	vector <string> final_result = letterCombinations(digits);

	/* Output */
	for(int i=0;i<final_result.size();i++)
	{
		cout << final_result[i] << " , ";
	}
	cout << endl;

	return 0;
}