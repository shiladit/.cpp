//Leetcode

class Solution {
public:
    int maxArea(vector<int>& height) {
        
        int left = 0;
        int right = height.size() - 1;;
        int water = 0;

        /* Start with the widest possible container by taking
        left index as the first element of array and right
        index as the last element of the array. Calculate the
        water that could be hold using the formula (right - left)
        multiplied by the minimum height of these two indices.
        Now whichever of these two heights is minimum, we can
        achieve a better height possibly if we skip that index 
        and look ahead.  */
        
        while(left < right)
        {
            int h = min(height[left],height[right]);
            water = max(water,(right-left)*h);
  
  			/* if left has the minimum height we
  			increase left else we decrease right*/
            if(height[left] == h)
                left++;
            else
                right--;
        }
        
        return water;
        
    }
};