//leetcode - 395

#include<iostream>
#include<map>
#include<string>
using namespace std;

/* Idea is to keep track of frequencies of all characters in the strings.
If one of the characters has a frequency less than k, means that char
won't be part of any substring that has all characters >=k. 
So we seggregate the string from there and call the longestSubstring function recursively */

int longestSubstring(string s, int k) 
{
       map <char,int> freq;
       int n = s.length();

       /* if k is 0 or 1, entire string will be output */
       if(k == 0 || k == 1)
           return n;
      
       /* if k is more than length of string or string length is 0, return 0 */ 
       if((k > n) || (n == 0))
           return 0;
      
       /* store frequency of char in the string/substring */ 
       for(int i=0;i<n;i++)
       {
           freq[s[i]] += 1;
       }
      
       /* break at the place where we encounter a character than has frequency less than k */ 
       int index = 0;
       while((index < n) && freq[s[index]] >= k)
           index++;
      
       /* if all characters have frequency more than equal to k, return entire string.length() */ 
       if(index == n)
           return n;
       
       /* else we recursively call on the splitted string */ 
       int left_string = longestSubstring(s.substr(0,index), k);

       /* if there are multiple characters with freq <k at the split point, then we want to skip all of them */
       int x = index+1;
       while((x < n) && (freq[s[x]] < k))
           x++;

       int right_string = longestSubstring(s.substr(x,n), k);
       
       return max(left_string,right_string);
}


int main()
{
	string s;
	cin >> s;
	int k;
	cin >> k;

	cout << longestSubstring(s,k) << endl;
	
	return 0;
}
