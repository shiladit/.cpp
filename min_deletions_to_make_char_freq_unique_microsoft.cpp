// Hackerrank
#include <iostream>
#include <map>
#include <set>
#include <unordered_map>
#include <vector>
#include <queue>
#include <stack>
#include <climits>
#include <cassert>
#include <algorithm>
using namespace std;

#define ll long long

/* Goal is to sort characters by frequencies in non-increasing order.
Then we look at adjacent frequencies, if they are equal we find out
frequency lower than it that doesn't exist */

static bool compare(int a,int b)
{
	if(a>b)
		return true;
	else
		return false;
}

int minDeletions(string s)
{
	vector <int> freq(26,0);

	/* find out frequency of each character in the string */
    for(int i=0;i<s.length();i++)
    {
        int index = s[i] - 'a';
        freq[index] += 1;
    }

    int sum = 0;
    
    /* sort by non-increasing order of frequencies */
    sort(freq.begin(),freq.end(),compare);

    set <int> mp;

    /* put frequencies in the map if not equal to 0 */
    for(int i=0;i<freq.size();i++)
        if(freq[i] != 0)
            mp.insert(freq[i]);

    for(int i=1;i<freq.size();i++)
    {
    	/* if freq is 0, we skip */
        if(freq[i] == 0)
            continue;

        /* if freq of current is same as last */
        else if(freq[i] == freq[i-1])
        {
            int val = freq[i];

            /* decrease val untill we don't find it in the map or it reaches 0 */
            while(val >= 0)
            {
                if(mp.find(val) == mp.end())
                {
                    sum += freq[i] - val;

                    /* if val != 0, we insert new val in the map */
                    if(val != 0)
                        mp.insert(val);

                    break;
                }
                /* decrease val */
                else
                    val--;
            }
        }
    }

    return sum;
}

int main()
{
	string s;
	cin >> s;

	cout << minDeletions(s) << endl;

	return 0;
}