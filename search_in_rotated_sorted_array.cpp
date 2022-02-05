#include <iostream>
#include <vector>

using namespace std;

/* this function returns the index where 
the search element is present, if element 
is not present return -1 */
int search(vector <int> &arr, int k)
{
	int n = arr.size();

	int lo = 0;
	int hi = (n-1);

	while(lo < hi)
	{
		int mid = (lo + hi)/2;

		/* smallest element will have both immediate left and right
		neighbour as greater than itself */
		if((arr[mid+1]%n > arr[mid]) && (arr[mid+n-1]%n > arr[mid]))
			return mid;

		/* Unsorted side will contain the smallest element of the array */
		if(arr[mid] > arr[hi])
			lo = mid+1;
		else
			hi = mid-1;
	}

	/* lo=hi after this point and both point to the index of the 
	smallest element in the array */

	int smallest_index = lo;
	lo = 0;
	hi = smallest_index-1;

	/* binary search on left part of smallest element */
	while(lo<=hi)
	{
		int mid = (lo+hi)/2;

		if(arr[mid] == k)
			return mid;

		if(arr[mid] > k)
			hi = mid - 1;
		else
			lo = mid + 1;
	}

	/* binary search on right part of smallest element */

	lo = smallest_index;
	hi = n;

	while(lo<=hi)
	{
		int mid = (lo+hi)/2;

		if(arr[mid] == k)
			return mid;

		if(arr[mid] > k)
			hi = mid - 1;
		else
			lo = mid + 1;
	}

	return -1;
}

int main()
{
	int n,k;
	cin >> n;

	vector <int> arr(n);

	for(int i=0;i<n;i++)
		cin >> arr[i];

	cin >> k;

	cout << search(arr,k) << endl;

	return 0;
}