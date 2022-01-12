#include <iostream>
#include <vector>
using namespace std;

int compute_lis(vector <int> &arr)
{
	int n = arr.size();
	int max_sub = 1;

	/* This result array stores the length of lis if it ends at index i 
	Start with all elements of result set to 1, since each can form a 1
	length lis. Now for every i, we look at all possible j before i. If
	arr[j] < arr[i], then we can safely say that lis at index i is 1 + lis
	at index j. (result[i] = result[j] + 1)
	*/
	vector <int> result(n,1);

	for(int i=0;i<n;i++)
	{
		for(int j=0;j<i;j++)
		{
			if((arr[i] > arr[j]) and result[i] < result[j] + 1)
			{
				result[i] = result[j] + 1;
				/* keeping track of max value of list seen so far */
				if(result[i] > max_sub)
				{
					max_sub = result[i];
				}
			}
		}
	}

	return max_sub;
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

	cout << compute_lis(arr) << endl;

	return 0;
}