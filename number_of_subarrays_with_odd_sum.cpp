// Leetcode
#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>
#include <cassert>
#include <algorithm>

using namespace std;

#define mod (1000000000 + 7)
#define ll long long

ll oddSum(vector <int> &arr)
{
	int n = arr.size();

	/* dp_odd[i] is a vector that says the number of subarrays with odd sum ending at i */
	vector <ll> dp_odd(n,0);
	/* dp_even[i] is a vector that says the number of subarrays with even sum ending at i */
	vector <ll> dp_even(n,0);

	if(arr[0] % 2 == 1)
		dp_odd[0] = 1;
	else
		dp_even[0] = 1;

	for(int i=1;i<n;i++)
	{
		/* when current element is odd
		we can extend odd by 1, since even + odd = odd;
		and for even, it will be same as previous odd, since odd + odd = even */
		if(arr[i] % 2 == 1)
		{
			dp_odd[i] = 1 + (dp_even[i-1]%mod);
			dp_even[i] = (dp_odd[i-1]%mod);
		}
		/* when current element is even
		we can extend even by adding the even no. to the previously computed even
		the new odd will be same as the previous odd, since an even number is added */
		else
		{
			dp_odd[i] = (dp_odd[i-1]%mod);
			dp_even[i] = 1 + (dp_even[i-1]%mod);
		}
	}

	ll sum = 0;

	for(int i=0;i<n;i++)
	{
		sum += dp_odd[i];
		sum = (sum%mod);
	}

	return sum;
}

int main()
{
	int n;
	cin >> n;

	vector <int> arr(n);

	/* i/p */
	for(int i=0;i<n;i++)
	{
		cin >> arr[i];
	}

	cout << oddSum(arr) << endl;

	return 0;
}