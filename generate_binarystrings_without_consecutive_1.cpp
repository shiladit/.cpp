#include <iostream>
using namespace std;

void print_bin(int index, int k, string s, bool prev_1)
{
	/* when ever string size becomes k, return */
	if(index == k)
	{
		cout << s << endl;
		return;
	}

	/* We divide into two cases
	1. previous number is 1 (prev_1 = true)
	2. previous number is 0 (prev_1 = false)
	if prev_1 is false, we add both 0 and 1 to the
	string till that point and pass prev_1 as false
	and true respectively.
	*/

	if(prev_1 == false)
	{
		string temp1 = s;
		string temp2 = s;

		temp1 = temp1 + '0';
		temp2 = temp2 + '1';

		print_bin(index+1, k, temp1, false);
		print_bin(index+1, k, temp2, true);
	}
	else // prev_1 == true
	{
		string temp3 = s;
		temp3 = temp3 + '0';
		print_bin(index+1, k, temp3, false);
	}

	return;
}

int main()
{
	int k;
	cin >> k;
	print_bin(0,k,"",false);

	return 0;
}
