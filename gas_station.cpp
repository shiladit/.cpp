//leetcode
#include<iostream>
#include<vector>
using namespace std;

int main()
{
	vector <int> gas;
	vector <int> cost;

	int n,temp;
	cin >> n;

	/* Inputs */
	for(int i=0;i<n;i++)
	{
		cin >> temp;
		gas.push_back(temp);
	}

	for(int i=0;i<n;i++)
	{
		cin >> temp;
		cost.push_back(temp);
	}
	/* end of Inputs */

	int viable_index = -1;

	/* for each starting position the amount of gas
	should be more than the cost, otherwise we look
	at the next starting position */
	for(int start=0;start<n;start++)
	{
		/* not feasible, look at next starting position */
		if(gas[start] < cost[start])
			continue;
		/* we keep track of the starting and ending indexes */
		int accumulated = gas[start] - cost[start];
		int cur_index = (start+1)%n;
		int end;
		if((start-1) >= 0)
			end = start - 1;
		else
			end = (n-1);

		/* path keeps track if we fail from
		that starting position (path == false) */
		bool path = true;

		while(cur_index != start)
		{
			accumulated = accumulated + gas[cur_index] - cost[cur_index];

			/* accumulated can be 0 at the end, not before */
			if((accumulated == 0) && (cur_index != end))
			{
				path = false;
			}
			else if (accumulated < 0)
				path = false;

			cur_index = (cur_index + 1)%n;
		}

		/* if we haven't failed */
		if(path)
			viable_index = start;
	}

	cout << viable_index << endl;

	return 0;
}
