#include <bits/stdc++.h>

using namespace std;


int main() {
   
    int n;
    cin >> n;
    
    while(n--){
        string s;
        cin >> s;
        
        map <char,int> umap;
        
        for(int i=0;i<s.length();i++){
            if(umap.find(s[i]) == umap.end())
                umap[s[i]] = 1;
        }
        
        map <char,int> :: iterator it;
        
        int count = 0;
        
        for(it = umap.begin();it != umap.end(); it++){
            count = count + it->second;
        }
        
        cout << count << endl;
    }
}