/* https://practice.geeksforgeeks.org/problems/find-largest-word-in-dictionary/0 */

#include <bits/stdc++.h>

using namespace std;

int main() {
	int t;
	cin >> t;
	
	
	while(t--){
	    int words;
	    cin >> words;
	    
	    string s,s1,s2;

	    vector <string> arr;
	    
	    for(int i=0;i<words;i++){
	        cin >> s;
	        arr.push_back(s);
	    }
	    
	    int max_count = -INT_MAX;
	    cin >> s1;
	    for(int i=0;i<words;i++){
	        int k=0;
	        int count=0;
	        
	        for(int j=0;j<s1.length();j++){
	            if(s1[j] == arr[i][k]){
	                k++;
	                count++;
	            }
	        }
            if(count >max_count){
                max_count =count;
                s2 = arr[i];
            }
	        
	    }
	    
	    cout << s2 << endl;
	    
	    
	}
	return 0;
}