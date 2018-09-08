#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int size,temp,k;
        cin >> size >> k;
        
        map <int,int> umap;
        vector <int> arr;
        
        for(int i=0;i<size;i++){
            cin >> temp;
            if(umap.find(temp) == umap.end())
                umap[temp] =1;
            else
               umap[temp]++;
        }

        for(int i=0;i<size;i++){
            cin >> temp;
            arr.push_back(temp);
        }
        
        bool pos = true;


        for(int i=0;i<size;i++){
           
            int num_map = k - arr[i];
            bool flag = false;
            
            for(int j=num_map;j<=k;j++){
                if(umap.find(j) != umap.end() && umap[j] > 0){
                        umap[j]--;
                        flag = true;
                        
                        break;
                }
            }
            if(flag == false){
                cout << "NO" << endl;
                pos = false;
                break;
            }
        }

        if(pos == true){
            cout << "YES" << endl;
        }      
        
    }
}