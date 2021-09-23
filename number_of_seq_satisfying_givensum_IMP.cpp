//Leetcode

class Solution {
public:
    #define ll long long

/* GIST: We sort the input array first, 
Then for every element i in the array, we try to find 
the maximum j such that i + j <= target. From here 
we can generate the number of substrings that could be 
formed with those elements. */
    
    int numSubseq(vector<int>& nums, int target) 
    {
        int n = nums.size();
        ll mod = 1000000007;
        
        vector <ll> pow(n,1);
        
        /* Pre calculated power function of 2*/
        for(int i=1;i<n;i++)
        {
            pow[i] = (2 * pow[i-1]) % mod;
        }
        
        sort(nums.begin(),nums.end());
        
        int i = 0;
        int j = n-1;
        ll res = 0;
        
        /* i has to be less than equal to j,
        otherwise we do same computations twice */
        while(i < n and i <= j)
        {
            /* find max j for every i such that i + j <= target */
            if((i <= j) and (nums[i] + nums[j] > target))
                j--;
            else
            {
                res = (res + pow[j-i]) % mod;
                i++;
            }
            
        }
        
        return res;     
    }
};