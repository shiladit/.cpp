// leetcode 
#include <iostream>
#include <vector>
#include <string>
using namespace std;
    
int match(string s, vector<string>& words) 
{
        vector < vector <int> > freq(26);
        vector <int> :: iterator it;

	/* make a 2d vector where we store
	characters in the string and their indices
	Naturally since indices always increase,
	the list will be sorted. This makes us think
	if we can use binary search on it */
	
        for(int i=0;i<s.length();i++)
        {
            freq[s[i]-'a'].push_back(i);
        }
        
        int count = 0;

        for(int i=0;i<words.size();i++)
        {
            string temp = words[i];
            int max_index = -1;
            bool is_subseq = true;

            for(int j=0;j<temp.size();j++)
            {
                char c = temp[j];
                int index = c - 'a';
                vector <int> &temp_vec = freq[index];
                it = upper_bound(temp_vec.begin(),temp_vec.end(), max_index);
                if(it != temp_vec.end())
                {
                    max_index = *it;
                }
                else
                {
                    is_subseq = false;
                    break;
                }
            }

            if(is_subseq)
                count++;
        }

        return count;
}

int main()
{
	string s;
	cin >> s;

	vector <string> words;
	int n;
	cin >> n;
	for(int i=0;i<n;i++)
	{
		string temp;
		cin >> temp;
		words.push_back(temp);
	}

	cout << match(s,words) << endl;

	return 0;
}
