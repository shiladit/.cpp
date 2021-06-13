#include <iostream>
#include <vector>
#include <stack>
using namespace std;

/* Idea is to look at the left wall and right wall for
every element and calculate water contained within these.

	for this we look at middle element and look at its
	left wall and right wall. Calculate the distance
	between the two, right_index - left_index + 1.
	And multiply this with the minimum height of these 2
	walls minus the size of the middle wall since it
	doesn't contribute to the total water held.

	** This will also work for middle wall of height 0,
	since that needs to be accounted for also.

   _
  | |      _
  | |  _  | |
 _| |_| |_| |_

*/

int trap(vector <int> &height)
{
	stack <int> stk;
	int n = height.size();
	int area = 0;

	for(int i=0;i<n;i++)
	{
		while(!stk.empty())
		{
			int top_index = stk.top();

			if(height[top_index] < height[i])
			{
				int mid_ht = height[top_index];
				stk.pop();

				/* if there is no left wall, break */
				if(stk.empty() == true)
					break;

				int left_ht = height[stk.top()];
				int left_index = stk.top();
				int right_ht = height[i];
				int right_index = i;

				int min_height = min(right_ht,left_ht) - mid_ht;
				int distance = right_index - (left_index + 1);

				area = area + (distance * min_height);
			}
				else
					break;
		}
		stk.push(i);
	}

	return area;
}

int main()
{
	int n,temp;
	cin >> n;

	vector <int> height;
	for(int i=0;i<n;i++)
	{
		cin >> temp;
		height.push_back(temp);
	}

	cout << trap(height) << endl;

	return 0;
}
