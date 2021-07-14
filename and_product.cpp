// Hackerrank  -- fetches 36.28/40.00 marks
#include <iostream>
#include <climits>
#include <cassert>
#include <cmath>
using namespace std;

#define ll long long

int main()
{
	ll q;
	cin >> q;

	while(q--)
	{
		ll l,r;
		cin >> l >> r;

		ll temp_l = l;
		ll times = 0;

		while(temp_l)
		{
			times++;
			temp_l = temp_l >> 1;
		}

		if(r <= pow(2,times))
		{
			ll val = l;
			int loops = 1;
			for(int itr=l+1;itr<=r;itr++)
			{	
				val = val & itr;
				/* Tappi */
				if(++loops > 2000)
					break;
			}
			cout << val << endl;
		}
		else
			cout << 0 << endl;
	}

	return 0;
}
