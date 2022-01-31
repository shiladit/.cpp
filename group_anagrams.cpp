//leetcode
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) 
    {
        unordered_map <string, vector <string> > mp;
        
        /* find the lexicographically smallest word possible
        with the set of characters and place the corresponding
        anagrams with the word in a map */
        for(int i=0;i<strs.size();i++)
        {
            string temp = strs[i];
            sort(temp.begin(),temp.end());
            
            mp[temp].push_back(strs[i]);
        }
        
        //stores result
        vector < vector <string> > res;
        
        unordered_map <string, vector <string> > :: iterator it;
        
        for(it=mp.begin();it!=mp.end();it++)
        {
            res.push_back(it->second);
        }
              
        return res;
    }
};