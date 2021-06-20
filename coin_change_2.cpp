//leetcode
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        
        int n = coins.size() + 1;
        int m = amount + 1;
        
        vector <vector <int> > aux(n,vector <int> (m));
 
/* in initial dp table we take no of ways of making 0,
from coins of any value as 1 */
        for(int i=0;i<n;i++)
        {
                for(int j=0;j<m;j++)
                {
                        if(j==0)
                            aux[i][j] = 1;
                }
        }
        
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<m;j++)
            {
		/* if value of current coin is more than
		the current amount, the current coin will
		not contribute anything to it, so we copy
		the value above */
                if(coins[i-1] > j)
                    aux[i][j] = aux[i-1][j];
                else
		/* if the value of current coin is less than
		equal to the current amount, then we have two cases
		1. How many ways the amount can be reached without using the current coin aux[i-1][j]
		2. How many ways we can reach the residual amount after using the current coin ( 1 * aux[i][residual]
		*/
                {
                    int residual = j - coins[i-1];
                    aux[i][j] = aux[i-1][j] + (1 * aux[i][residual]);
                }       
            }
        }

        return aux[n-1][m-1];
    }
};
