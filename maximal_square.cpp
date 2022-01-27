//Leetcode

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) 
    {
        int n = matrix.size();
        int m = matrix[0].size();
        
        vector < vector <int> > result(n+1, vector <int> (m+1));
        
        /* minimum size of square */
        int max_square = 0;
        
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                /* if the input matrix has a 1 */
                if(matrix[i-1][j-1] == '1')
                {
                    /* Look at 3 adjacent elements and take min of them + 1 */
                    result[i][j] = min({result[i-1][j-1],result[i-1][j],result[i][j-1]}) + 1;

                    /* Keep track of the max size of square seen so far */
                    max_square = max(result[i][j], max_square);
                }
            }
        }
        
        /* return area of the square */
        return max_square * max_square;
    }
};