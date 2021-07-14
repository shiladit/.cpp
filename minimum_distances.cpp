// Hackerrank
#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>
#include <queue>
#include <stack>
#include <climits>
#include <cassert>
using namespace std;

#define ll long long

/* keep track of current minimum distance for each value and
the index at which the current element is last seen */
int main()
{
	int n;
	cin >> n;

	map <int, pair <int,int> > mp;
	vector <int> arr(n);

	for(int i=0;i<n;i++)
	{
		cin >> arr[i];
		mp[arr[i]] = make_pair(-1,INT_MAX);
	}

	/* keeps track of the overall minimum distance between similar elements */
	int overall_min = INT_MAX;

	for(int i=0;i<n;i++)
	{
		pair <int,int> p = mp[arr[i]];
		int prev_index = p.first;

		/* when already the element is seen */
		if(prev_index >= 0)
		{
			int dist = i - prev_index;
			if(dist < overall_min)
			{
				overall_min = dist;
			}

			mp[arr[i]] = make_pair(i,dist);	
		}
		/* element is seen for first time */
		else
		{
			mp[arr[i]] = make_pair(i,INT_MAX);
		}
	}

	if(overall_min != INT_MAX)
	{
		cout << overall_min << endl;
	}
	else
	{
		cout << "-1" << endl;
	}

	return 0;
}