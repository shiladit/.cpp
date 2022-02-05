#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

/* Idea is to look at the left wall and right wall for
every element and calculate water contained within these.

	for this we look at middle element and look at its
	left wall and right wall (max on the left side of
	the array and max on the right side of the array). 
	Calculate the distance between the two, 
	right_index - left_index + 1.
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
	int n = height.size();
	int water = 0;

	int max_left[n];
	int max_right[n];

	max_left[0] = height[0];

	for(int i=1;i<n;i++)
	{
		max_left[i] = max(max_left[i-1],height[i]);
	}

	max_right[n-1] = height[n-1];

	for(int i=n-2;i>=0;i--)
	{
		max_right[i] = max(max_right[i+1],height[i]);
	}

	for(int i=1;i<n-1;i++)
	{
		int temp = min(max_right[i+1],max_left[i-1]);
		if(temp > height[i])
			water += temp - height[i];
	}

	return water;
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
