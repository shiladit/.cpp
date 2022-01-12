/* Maximum value that can be held in a 0-1 Knapsack
such that weight requirments are satisfied */
#include <iostream>

using namespace std;

int knapSack (int W,int wt[],int val[],int n)
{
	int arr[n+1][W+1];

    //DP 
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=W;j++)
		{
			    if((i==0) || (j==0))
			    	arr[i][j] = 0;
				else if (wt[i-1]<=j)			    
					arr[i][j] = max (arr[i-1][j] ,val[i-1] + arr[i-1][j-wt[i-1]]);
				else
					arr[i][j] = arr[i-1][j];
		}
	}	

	return arr[n][W] ;		
}


int main()
{
	/* Values */
    int val[] = {1,4,5,7};

    /* Weights */
    int wt[] = {1,3,4,5};

    /* Target Weight */
    int  W = 7;

    int n = sizeof(val)/sizeof(val[0]);

    cout << knapSack(W, wt, val, n) << endl;

    return 0;
}