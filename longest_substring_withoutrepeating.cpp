#include <iostream>
#include <map>
#include <string>
using namespace std;

int long_sub_worep(string s)
{
	if(s.length() == 0)
		return 0;

	if(s.length() == 1)
		return 1;

	map <char,int> umap;
	int i=0;
	int j=0;
	int n = s.length();
	int max_len = 0;

	while(j < n)
	{
        // not present in map
		if(umap.find(s[j]) == umap.end())
		{
			umap[s[j]] = j;
		}
        // present in map
		else
		{
			int index = umap[s[j]];
			if(i <= index)
			    i = index+1;

			umap[s[j]] = j;
		}

		max_len = max(max_len,(j-i) + 1);
		j++;
	}

	return max_len;
}

int main()
{
	string s;
	cin >> s;

	int val = long_sub_worep(s);
	cout << val << endl;

	return 0;
}
