#include <iostream>
#include <vector>
using namespace std;

bool increasing_triplet(vector <int> &arr)
{
	int n = arr.size();
	vector <int> dp(n,1);
	bool flag = false;

	for(int i=0;i<n;i++)
	{
		for(int j=0;j<i;j++)
		{
			if((arr[i] > arr[j]) and (dp[i] < 1 + dp[j]))
			{
				dp[i] = 1 + dp[j];
				if(dp[i] >= 3)
				{
					flag = true;
					break;
				}
			}

		}
	}

	return flag?true:false;
}


int main()
{
	int n;
	cin >> n;
	vector <int> arr(n);
	for(int i=0;i<n;i++)
		cin >> arr[i];

	if(increasing_triplet(arr))
		cout << "True\n";
	else
		cout << "False\n";
	
	return 0;

}