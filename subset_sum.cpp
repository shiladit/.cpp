#include <iostream>
using namespace std;

bool isSubsetSum(int arr[],int n,int sum)
{
	bool dp[n+1][sum+1];

	//Initialize
	for(int i=0;i<n+1;i++)
	{
		for(int j=0;j<sum+1;j++)
		{
			if(i==0)
				dp[i][j] = false;
			
			else if (j==0)
				dp[i][j] = true;
		}
	}

	dp[0][0] = true;

	//DP
	for(int i=1;i<n+1;i++)
	{
		for(int j=1;j<sum+1;j++)
		{
			/* if current element is greater than required sum,
			we take it's value from above, as it can or cannot be
			made without using the current element */
			if (arr[i-1]>j)
				dp[i][j] = dp[i-1][j];

			/* if current element is equal to the required sum,
			then we update table as true */
			else if(arr[i-1]==j)
				dp[i][j] = true;
			
			/* if current element is smaller than required sum,
			we check if we are able to make the current-required sum
			from the previous elements */
			else if (!dp[i-1][j])
				dp[i][j] = dp[i-1][j-arr[i-1]];
			else 
				dp[i][j] = true ;
    }
	}

/* DEBUG */
	// for(int i=1;i<n+1;i++)
	// {
	// 	for(int j=1;j<sum+1;j++)
	// 	{
	// 		cout << dp[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }	

	return dp[n-1][n-1];
 }

int main()
{
  int arr[] = {3,4,1,2};
  int sum = 6;
  int n = sizeof(arr)/sizeof(arr[0]);

  if(isSubsetSum(arr, n, sum))
  	cout << "true\n";
  else
  	cout << "false\n";

  return 0;
}