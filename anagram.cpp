#include <bits/stdc++.h>

using namespace std;

long check_count(map <char,long> umap){
    map <char,long> :: iterator it;


    long sum =0;

    for(it = umap.begin();it != umap.end();it++)
        sum = sum + it->second;

    return sum;
}

int main() {
    long q,temp;
    string s;
    cin >> q;
    
    while(q--){
        cin >> s;
        
        map <char,long> umap;
        
        if(s.length()%2 != 0){
            cout << "-1" << endl;
        }
        else {
            int j;
            long len= s.length();
            for(long i=0;i<len/2;i++){
                umap[s[i]]++;
                j=i;
            }            
            
            
            for(long i=j+1;i<len;i++){
                if(umap.find(s[i]) != umap.end() && umap[s[i]]>0)
                    umap[s[i]]--;
            }
                
            cout << check_count(umap) << endl;

            
        }
    }
}


