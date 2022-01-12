//Leetcode

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        
        int sum = 0;
        int n = nums.size();
        int result = 0;
        
        unordered_map <int,int> mp;

        /* for every element in the array of 0 and 1's,
        we replace 0's with -1. This way if we do a contiguous sum
        of the array and at any point we get 0, means the elements
        in between have equal number of 0's and 1's */
        
        for(int i=0;i<n;i++)
        {
            if(nums[i] == 0)
                sum = sum-1;
            else
                sum = sum+1;
            
            /* if sum adds to 0 */
            if(sum == 0)
                result = max(result,i+1);
            
            /* if we have not encountered a sum before, we store the
            index at which we get the sum value */
            if(mp.find(sum) == mp.end())
            {
                mp[sum] = i;
            }
            /* if we have ecountered the sum before, means the elements
            between these two same values add upto 0, vis as vis they have
            equal number of 0's and 1's. From there we calculate the 
            largest contiguous subarray with equal number of 0's and 1's */
            else
            {
                result = max(result,(i-mp[sum]));
            }
        }
        
        return result;
    }
};