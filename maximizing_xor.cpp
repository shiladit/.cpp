// Hackerrank
#include <iostream>
#include <map>
#include <set>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <queue>
#include <stack>
#include <climits>
#include <cassert>
using namespace std;

int main()
{
	int max_val = INT_MIN;

	int l,r;
	cin >> l >> r;

	for(int i=l;i<=r;i++)
	{
		for(int j=l;j<=r;j++)
		{
			int val = i^j;
			if(val > max_val)
				max_val = val;
		}
	}

	cout << max_val << endl;

	return 0;
}