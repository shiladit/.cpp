class Solution
{
public:
    vector <vector <int> > result;
    
    vector<vector<int>> subsets(vector<int>& nums) 
    {
        int n = nums.size();
        int range = pow(2,n);
        
        for(int i=0;i<range;i++)
        {
            int index = (n-1);
            vector <int> temp;
            int j = i;
            
            while(j)
            {
                if(j & 1)
                    temp.push_back(nums[index]);
                
                j = j >> 1;
                index--;
            }
            
            result.push_back(temp);
        }

        return result;
    }
};
