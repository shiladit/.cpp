#include <bits/stdc++.h>

using namespace std;


int main() {
    long n,temp;
    cin >> n;
    string s1,s2;
    
    map <string,long> umap;
    
    for(int i=0;i<n;i++){
        cin >> s1;
        if(s1 == "add"){
            cin >> s2;
            for(int j=1;j<=s2.length();j++){
                string s = s2.substr(0,j);
                // cout << s << endl;
                if(umap.find(s) == umap.end())
                    umap[s]=1;
                else
                    umap[s]++;
            }
            
        }
        else
         {
            cin >> s2;
            cout << umap[s2] << endl;
            
        }
    }
}