// Hackerrank
#include <iostream>
#include <climits>
#include <cassert>
#include <cmath>
using namespace std;

#define ll long long

/* this functions calculates XOR based on conditions 
between two margins */
ll calc(ll left,ll right)
{
	ll sum = 0;

	for(ll i=left;i<=right;i++)
	{
		if((i%4) == 0)
			sum = sum ^ i;
		else if ((i%4) == 1)
			sum = sum ^ 1;
		else if((i%4) == 2)
			sum = sum ^ (i+1);
		else
			sum = sum ^ 0;
	}

	return sum;
}

int main()
{
	ll q;
	cin >> q;

	while(q--)
	{
		ll left,right;
		cin >> left >> right;
		
		/* We notice that XOR-ed based on conditions in the question
		amounts to 0 for every 8 elements (0-7),(8-15) and so on. 
		We therefore calculate the smallest number greater than left that
		is a multiple of 8 and the largest number less than right that is 
		a multiple of 8. We calculate XOR between these two intervals separately
		and add them up to form the overall XOR */
		ll l_margin = ((ceil((double)left/8))*8);
		ll r_margin = ((floor((double)right/8))*8);

		ll sum_1 = calc(left,l_margin-1);
		ll sum_2 = calc(r_margin,right);

		cout << (sum_1 ^ sum_2) << endl;
	}

	return 0;
}
