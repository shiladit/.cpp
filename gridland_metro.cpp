// hackerrank
#include <iostream>
#include <map>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

#define ll long long
map <ll, vector <pair <ll,ll> > > mp;

ll gridland(ll n,ll m,ll k,vector < vector <ll> > &track)
{
	ll moves = n * m;
	map <ll, vector <pair <ll,ll> > > :: iterator it;

	/* pick each element from the map and take its key.
	The key is a vector of pairs with starting and closing
	indexes of the railway tracks. We sort them by the starting
	index and try to merge intervals */
	for(it = mp.begin(); it != mp.end(); it++)
	{
		vector <pair <ll,ll> > temp_arr = it->second;
		sort(temp_arr.begin(),temp_arr.end());

		/* this routine merges overlapping intervals */
		stack <pair <ll,ll> > stk;
		for(int i=0;i<temp_arr.size();i++)
		{
			if(stk.empty())
			{
				stk.push(temp_arr[i]);
			}
			else
			{
				pair <ll,ll> p = temp_arr[i];
				if((p.first >= stk.top().first) and (p.first <= stk.top().second))
				{
					if(p.second > stk.top().second)
					{
						stk.top().second = p.second;
					}
				}
				else
				{
					stk.push(temp_arr[i]);
				}
			}
		}

		vector <pair <ll,ll> > temp_res;
		while(!stk.empty())
		{
			temp_res.push_back(stk.top());
			stk.pop();
		}

		it->second = temp_res;
	}

	/* at this point we are left with merged intervals for every row. 
	You can check by uncommenting the below code */

	/* DEBUG
	for(it = mp.begin(); it != mp.end(); it++)
	{
		cout << it->first << " --> ";
		vector <pair <ll,ll> > v = it->second;
		for(int i=0;i<v.size();i++)
		{
			cout << v[i].first << "," << v[i].second << " ";  
		}
		cout << endl;
	}
	*/

	ll count = 0;

	/* Count tracks that are covered by railway lines, (ending_index - starting_index) + 1 */
	for(it = mp.begin(); it != mp.end(); it++)
	{
		vector <pair <ll,ll> > v = it->second;
		for(int i=0;i<v.size();i++)
		{
			count += (v[i].second - v[i].first) + 1;  
		}
	}

	/* No. of lampposts = total moves - cells covered by railway tracks */
	return moves - count;
}

int main()
{
	ll n,m,k;
	cin >> n >> m >> k;
	vector < vector <ll> > track;

	for(int i=0;i<k;i++)
	{
		int row,l,r;
		cin >> row >> l >> r;
		track.push_back({row,l,r});
		/* store starting and ending indexes of rail tracks in 
		corresponding rows of the map */
		mp[row].push_back(make_pair(l,r));
	}

	cout << gridland(n,m,k,track) << endl;

	return 0;
}
