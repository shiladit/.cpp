class Solution {
public:
    bool canJump(vector<int>& nums) {

        /* max that can be reached */
        int max_reach = 0;
        int index = 0;
        int n = nums.size();
        
        /* make sure index which is checked is less than n and
        also less than equal to the maximum reachable index */
        while(index < n and (index <= max_reach))
        {
            max_reach = max(max_reach,nums[index]+index);
            index++;
        }
        
        /* if we are able to reach the end , we return true */
        if(index == n)
            return true;
        else
            return false;
    }
};
