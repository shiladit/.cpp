#include <vector>
#include <iostream>
using namespace std;

int longest_sum_subarray(vector <int> &arr)
{
	int max_so_far = 0;
	int max_ending_here = 0;

	/* The subarray might not contain a single element
	if all the elements are negative. Since we get max
	subarray sum as 0, by not including any element */

	for(int i=0;i<arr.size();i++)
	{
		max_ending_here = max_ending_here + arr[i];
		max_so_far = max(max_so_far,max_ending_here);

		/* if max_ending_here is negative, we make it 0 */	
		if(max_ending_here < 0)
			max_ending_here = 0;
	}

	return max_so_far;
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

	cout << longest_sum_subarray(arr) << endl;

	return 0;
}