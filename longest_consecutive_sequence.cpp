//leetcode

/* The idea is to put values in a map and check 
for the maximum consecutive numbers */

class Solution {
public:
    map <int,int> umap;
    
    int longestConsecutive(vector<int>& nums) 
    {
	/* if there is nothing in nums we
	return 0 */
        if(nums.size() == 0)
            return 0;
        
        for(int i=0;i<nums.size();i++)
            umap[nums[i]] = 1;
        
	/* at any case for the worst
	case longest consequence sequence
	will be atleast 1 */
        int longest_cons_seq = 1;
        map <int,int> :: iterator it;
        
        it = umap.begin();
        while(it != umap.end())
        {
            int elem = it->first;
            int cons_seq = 1;
            
            it++;
            while(it != umap.end() && it->first == elem + 1)
            {
                elem = it->first;
                it++;
                cons_seq++;
            }
            
            if(cons_seq > longest_cons_seq)
                longest_cons_seq = cons_seq;
        }
        return longest_cons_seq ;
    }
};
