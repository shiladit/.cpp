#include <iostream>
#include <stack>
#include <vector>

using namespace std;

/* GIST: For each bar of the histogram, we would want to calculate the max area
that wholly contains that bar. So we look at bars which are strictly lesser than
itself to its left and right. Obviously those are the bars we wont be considering.

Area of bar[i] = (index of right_smaller[i] - index of left_smaller[i] + 1) * height of bar[i]

*/

/* calculate first bar to the left with lesser height than bar[i] */
vector <int> calculate_left(vector <int> &heights)
{
	stack <int> stk;
	int n = heights.size();
	vector <int> result(n);

	for(int i=0;i<n;i++)
	{
		if(stk.empty())
		{
			result[i] = 0;
		}
		else
		{
			while(!stk.empty() && heights[stk.top()] >= heights[i])
			{
				stk.pop();
			}

			if(stk.empty())
			{
				result[i] = 0;
			}
			else
			{
				result[i] = stk.top()+1;
			}
		}

		stk.push(i);
	}

	return result;
}

/* calculate first bar to the right with lesser height than bar[i] */
vector <int> calculate_right(vector <int> &heights)
{
	stack <int> stk;
	int n = heights.size();
	vector <int> result(n);

	for(int i=n-1;i>=0;i--)
	{
		if(stk.empty())
		{
			result[i] = (n-1);
		}
		else
		{
			while(!stk.empty() && heights[stk.top()] >= heights[i])
			{
				stk.pop();
			}

			if(stk.empty())
			{
				result[i] = (n-1);
			}
			else
			{
				result[i] = stk.top()-1;
			}
		}

		stk.push(i);
	}

	return result;
}

int calc_largest_hist(vector <int> &arr)
{
	vector <int> left_smaller = calculate_left(arr);
	vector <int> right_smaller = calculate_right(arr);

	int max_area = -INT_MAX;

	/* Calculating maximum area */
	for(int i=0;i<arr.size();i++)
	{
		max_area = max(max_area,(right_smaller[i]-left_smaller[i] + 1)*arr[i]);
	}

	return max_area;
}

int main()
{
	int n;
	cin >> n;

	vector <int> arr(n);

	for(int i=0;i<n;i++)
	{
		cin >> arr[i];
	}

	cout << calc_largest_hist(arr) << endl;

	return 0;
}

/* Test Case

i/p 
6
2 1 5 6 2 3

o/p
10

*/