#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector < vector <int> > threeSum(vector <int> &nums)
{
	int n = nums.size();
	vector < vector <int> > result;

	/* if size < 3, we cant form a triplet */
	if(n < 3)
		return result;

	/* sorting will help us skip over duplicates */
	sort(nums.begin(),nums.end());

	for(int i=0;i<n;i++)
	{
		/* the idea is we process every element once when they arrive and skip over duplicate elements */
		if((i > 0 && i < n) and (nums[i] == nums[i-1]))
			continue;

		int low = i+1;
		int high = n-1;
		int target = -nums[i];

		while(low < high)
		{
			int sum = nums[low] + nums[high];

			if(sum < target)
				low++;
			else if (sum > target)
				high--;
			else // sum == target
			{
				/* when we have updated the result vector, we want to skip over same elements that can
				contribute to the result, this is most important funda in this problem */
				result.push_back({nums[i],nums[low],nums[high]});
				while(low < high)
				{
					if(nums[low] == nums[low + 1])
						low++;
					else
						break;
				}
				while(low < high)
				{
					if(nums[high] == nums[high - 1])
						high--;
					else
						break;
				}

				low++;
				high--;
			}
		}
	}

	return result;
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

	vector < vector <int> > result = threeSum(arr);
	for(int i=0;i<result.size();i++)
	{
		for(int j=0;j<result[i].size();j++)
		{
			cout << result[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}
