class Solution {
public:
    /* GIST:
    in the first pass I record counts of every character in a hashmap
    in the second pass I locate the first character that appear less than k times in the string. this character is definitely not included in the result, and that separates the string into two parts.
    keep doing this recursively and the maximum of the left/right part is the answer.
    */

    int longestSubstring(string s, int k) 
    {
        /* Map to store frequency of characters occuring in the string */
        map <char,int> freq;
        int n = s.length();

        /* if k is 0 or 1, return the length of the entire string */
        if(k == 0 || k == 1)
            return n;

        /* if k is more than string size or the string size if 0, then return 0 */
        if((k > n) || (n == 0))
            return 0;
        
        /* calculate frequency of characters in the map for the string */
        for(int i=0;i<n;i++)
        {
            freq[s[i]] += 1;
        }
        
        /* Skip indexes which have characters >=k in the map */
        int index = 0;
        while((index < n) && freq[s[index]] >= k)
            index++;
        
        /* if all characters are already >=k, return the total length of the string */
        if(index == n)
            return n;
        
        /* we are splitting the string into left with all character frequencies >= k */
        int left_string = longestSubstring(s.substr(0,index), k);

        /* we can skip indices with character frequencies <k */
        int x = index+1;
        while(x < n && freq[s[x]] < k)
            x++;
        
        /* the right string has all or some characters >= k with the first character in the string appearing >=k for sure */
        int right_string = longestSubstring(s.substr(x,n), k);
        
        /* Taking max of the two */
        return max(left_string,right_string);
        
    }
};