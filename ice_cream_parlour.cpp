#include <bits/stdc++.h>

using namespace std;

int main() {
    
    long t,m,n,temp;
    cin >> t;
    
    while(t--){
        cin >> m; //Money pooled
        cin >> n; //Flavours of ice-cream available
        
        map <long,long> umap;
        vector <long> arr;
        
        for(long i=0;i<n;i++){
            
            cin >> temp;
            arr.push_back(temp);
            umap[temp]= i+1;
        }
        
        for(int i=0;i<arr.size();i++){
            if(umap.find(m-arr[i]) != umap.end()){
                if(i+1 != umap[m-arr[i]]){
                    cout << i+1 << " " << umap[m-arr[i]] << endl;
                    break;
                }
                else
                    ;
            }   
        }
        
    }
    
}