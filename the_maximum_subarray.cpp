#include <iostream>
#include "limits.h"
#include <vector>
using namespace std;

#define ll long long

int main()
{
	ll t;
	cin >> t;

while(t--)
	{

	ll n,temp;
	cin >> n;

	vector <ll> arr;

	for(int i=0;i<n;i++)
	{
		cin >> temp;
		arr.push_back(temp);
	}

	/* Finding max subarray */

	/* Three cases can arise when i look
	at array elements 1 by 1:
	1. it is part of the cumulative sum that produces maximum_cumulative_sum
	2. it doesn't take any part in the cumulative sum since it doesn't produce
	the maximum cumulative sum at the moment, maybe further down the line it can
	be part of it. So we increment the cumulative sum(cum_sum). if cum_sum < 0, reset
	3. the maximum cumulative sum at the moment can be obtained by only selecting the
	current element. So we make cum_sum =0 and max_cum_sum = value of array_element.
	*/
	ll cum_sum = 0;
	ll max_cum_sum = LLONG_MIN;

	for(int i=0;i<n;i++)
	{
		cum_sum += arr[i];

		if(cum_sum > max_cum_sum)
		{
			max_cum_sum = cum_sum;
		}

		if(arr[i] > max_cum_sum)
		{
			cum_sum = 0;
			max_cum_sum = arr[i];
		}

		if(cum_sum < 0)
		{
			cum_sum = 0;
		}
	}

	/* Find max subsequence */

	ll largest_no = LLONG_MIN;
	ll max_seq_sum = 0;

	for(int i=0;i<n;i++)
	{
		if((arr[i] + max_seq_sum) > max_seq_sum)
		{
			max_seq_sum += arr[i] ;
		}

		if(arr[i] > largest_no)
		{
			largest_no = arr[i];
		}
	}

	if(max_seq_sum == 0)
		cout << max_cum_sum << " " << largest_no << endl;
	else
		cout << max_cum_sum << " " << max_seq_sum << endl;
	}
}
