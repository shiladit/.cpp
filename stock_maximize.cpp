#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define ll long long

/* DP - Not needed
Approach: keep buying till you get to the max value, this is the point where selling
can give max profit. Now look at the next maximum and do the same. */

ll stock_maximize(vector <ll> &prices)
{
	ll profit = 0;
	ll n = prices.size();
	priority_queue < pair <ll,ll> > pq;

	/* Using Max-Heap to keep track of max elements and their indices */
	for(int i=0;i<n;i++)
	{
		pq.push(make_pair(prices[i],i));
	}

	ll start = 0; ll spent = 0;

	for(int i=0;i<n;i++)
	{
		/* if index already passed, then it makes no sense to check max.
		keep popping untill we find a max whose index we are yet to reach */
		while(pq.top().second < i)
		{
			pq.pop();
		}

		/* A valid max is seen, sell stocks */
		if(i == pq.top().second)
		{
			profit += ((i-start) * prices[i]) - spent;
			pq.pop();
			start = i+1;
			spent = 0;
		}
		/* not a max, keep buying stocks */
		else
		{
			spent += prices[i];
		}
	}

	/* return accumulated profit */
	return profit;
}

int main()
{
	ll t;
	cin >> t;

	while(t--)
	{
		ll n;
		cin >> n;
		vector <ll> prices(n);

		for(int i=0;i<n;i++)
		{
			cin >> prices[i];
		}

		cout << stock_maximize(prices) << endl;
	}

	return 0;
}