#include <iostream>
using namespace std;

void binary_even(string s, int len, int k, int l_sum, int r_sum)
{
	if(len > k)
		return;

	if((len == k) && (l_sum == r_sum))
	{
		cout << s << endl;
		return;
	}

	binary_even("0" + s + "0", len+2, k, l_sum, r_sum);
	binary_even("0" + s + "1", len+2, k, l_sum, r_sum+1);
	binary_even("1" + s + "0", len+2, k, l_sum+1, r_sum);
	binary_even("1" + s + "1", len+2, k, l_sum+1, r_sum+1);

	return;
}


int main()
{
	int k;
	cin >> k;

	if(k % 2 == 0)
	{
		binary_even("",0,k,0,0);
	}
	else
	{
		binary_even("0",1,k,0,0);
		binary_even("1",1,k,0,0);
	}

	return 0;
}
