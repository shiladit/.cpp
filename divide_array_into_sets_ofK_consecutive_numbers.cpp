//leetcode

class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) 
    {
        
        int n = nums.size();

        if(n % k != 0)
            return false;
        
        map <int,int> mp;
        map <int,int> :: iterator it;
        
        /* creating map of frequencies */
        for(int i=0;i<n;i++)
        {
            mp[nums[i]]++;
        }
        
        /* We decrement count for k successive integers,
        starting from the front of the hashmap */
        for(it=mp.begin(); it != mp.end() ; it++)
        {
            while(it->second)
            {
                for(int i=it->first;i<it->first+k;i++)
                {
                    mp[i]--;
                    /* if at any point frequency of any integer becomes < 0,
                    return false */
                    if(mp[i] < 0)
                        return false;
                }
            }
        }
        
        return true;
    }
};