class Solution {
public:

    int timeDiff(string s, string t)
    {
        int h1 = stoi(s.substr(0,2));
        int m1 = stoi(s.substr(3,2));
        int h2 = stoi(t.substr(0,2));
        int m2 = stoi(t.substr(3,2));
        
        return ((h1-h2)*60) + (m1-m2);
    }
    
    int findMinDifference(vector<string>& timePoints) 
    {
        int n = timePoints.size();
        sort(timePoints.begin(),timePoints.end());
        
        int min_diff = 1440;
        
        for(int i=0;i<n;i++)
        {
        	/* comparing two adjacent elements, last element is compared
        	with first element */
            int diff = abs(timeDiff(timePoints[(i-1+n)%n],timePoints[i]));
            diff = min(diff, 1440-diff);
            if(diff < min_diff)
                min_diff = diff;
        }
        
        return min_diff; 
    }
};