#include <bits/stdc++.h>
using namespace std;

void print_even(string s, int len, int k, int no1_l, int no1_r)
{
	if(len > k)
		return;

	if((len == k) && (no1_l == no1_r))
	{
		cout << s << endl;
		return;
	}

	string temp = s;
	print_even("0" + temp + "0", len+2, k, no1_l, no1_r);
	print_even("0" + temp + "1", len+2, k, no1_l, no1_r+1);
	print_even("1" + temp + "0", len+2, k, no1_l+1, no1_r);
	print_even("1" + temp + "1", len+2, k, no1_l+1, no1_r+1);

	return;
}

int main()
{
	int k;
	cin >> k;

	assert(k >= 2);
	assert(k%2 == 0);

	/* the middle two elements can be
	00 or 01 or 10 or 11. We grow from
	that point. We track count of the
	number of 1's on the LHS and RHS.
	*/
	print_even("00",2,k,0,0);
	print_even("01",2,k,0,1);
	print_even("10",2,k,1,0);
	print_even("11",2,k,1,1);

	return 0;
}
