class Solution {
public:
    static bool compare(pair <int,int> &a,pair <int,int> &b)
    {
        if(a.second > b.second)
            return true;
        else
            return false;
    }
    
    vector<int> topKFrequent(vector<int>& nums, int k) 
    {
        map <int, int> mp;
        map <int, int> :: iterator it;
        int n = nums.size();
        
        /* store elements and the number of times they appear in nums */      
        for(auto i : nums)
            mp[i]++;
        
        vector <pair <int,int> > arr;
        
        /* store the map in a vector, so we can sort it */
        for(it=mp.begin();it!=mp.end();it++)
        {
            arr.push_back(make_pair(it->first,it->second));
        }
        
        /* sorting based on number of times each element appears, compare sorts
        with the most repeated element first and subsequent elements in decreasing
        order of repetitions */
        sort(arr.begin(),arr.end(),compare);
        
        /* return the first k elements from this sorted arrary */
        vector <int> result;
        for(int i=0;i<k;i++)
        {
            result.push_back(arr[i].first);
        }
        
        return result;
    }
};