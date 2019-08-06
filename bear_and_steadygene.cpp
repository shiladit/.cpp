#include <bits/stdc++.h>
using namespace std;

int main() {
    
    int length;
    cin >> length;

    string s;
    cin >> s;

    map <char,int> hash;
    map <char,int> pat;

    
    for(int i=0;i<s.length();i++){
        hash[s[i]]++;
    }   

    map <char,int> :: iterator it;


    pat['A'] = 0;
    pat['C'] = 0;
    pat['G'] = 0;
    pat['T'] = 0;

    
    int pattern_len = 0;

    bool flag = false;

    for(it = hash.begin(); it != hash.end(); it++){
        if(it->second > (length/4)){
        	flag = true;
            // cout << it->first << " -- " << it->second << endl; 
            pat[it->first] = it->second - (length/4);
            pattern_len += it->second - (length/4);
        }
    }

   

    int start = 0, min_len = INT_MAX; 
    hash.clear();
   
    int count = 0; // count of characters 

    if(flag){
	    for (int j = 0; j < length ; j++) 
	    { 
	        hash[s[j]]++; 


	        if (pat[s[j]] != 0 && hash[s[j]] <= pat[s[j]] ) 
	            count++;

	        if(count == pattern_len){
	            while ( hash[s[start]] > pat[s[start]] || pat[s[start]] == 0) 
	            { 
	  
	                if (hash[s[start]] > pat[s[start]]) 
	                    hash[s[start]]--; 

	                start++; 
	            } 
	            int len_window = j - start + 1;

	            if (min_len > len_window) 
	            { 
	                min_len = len_window; 
	            } 
	        }
	    }
	    cout << min_len << endl;
	}
	else
		cout << "0" << endl;
      
}
