#include <iostream>
#include <vector>
#include <stack>
using namespace std;

/* Idea is similar to finding next smaller element on left
using a stack. But here we keep track of the indices as well.
We add the result of the items popped to get the current value */

vector <int> stock_spanner(vector <int> &prices)
{
	/* stack with value and index */
	stack <pair <int,int> > stk;
	/* result vector */
	vector <int> result(prices.size());

	for(int i=0;i<prices.size();i++)
	{
		int sum = 1;

		/* While stack is not empty and top element is smaller than current element,
		keep popping */
		while(!stk.empty() && (stk.top().first < prices[i]))
		{
			pair <int,int> p = stk.top();
			/* Keep adding the result of the popped elements */
			sum = sum + result[p.second];
			stk.pop();
		}

		/* mandatory push each element and its index */
		stk.push(make_pair(prices[i],i));
		result[i] = sum;
	}

	return result;
}

int main()
{
	int n;
	cin >> n;

	vector <int> prices(n);

	for(int i=0;i<n;i++)
	{
		cin >> prices[i];
	}

	vector <int> result = stock_spanner(prices);

	for(int i=0;i<result.size();i++)
	{
		cout << result[i] << " ";
	}
	cout << endl;

	return 0;
}

/* 
i/p 
7
100 80 60 70 60 75 85

o/p
1 1 1 2 1 4 6
*/