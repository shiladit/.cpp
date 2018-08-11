#include <bits/stdc++.h>

using namespace std;


int main() {
    long n1,n2,n3,temp,sum = 0;
    cin >> n1 >> n2 >> n3;
    
    map <long,long> umap;
    
    vector <long> stack1;
    vector <long> stack2;
    vector <long> stack3;
    
     for(int i=0;i<n1;i++){
        cin >> temp;
        stack1.push_back(temp);
    }
    
    
     for(int i=0;i<n2;i++){
        cin >> temp;
        stack2.push_back(temp);
    }
    
    
     for(int i=0;i<n3;i++){
        cin >> temp;
        stack3.push_back(temp);
    }
    
    sum=0;
    
    for(int i=n1-1;i>=0;i--){
        temp = stack1[i];
        sum = sum + temp;
        // cout << sum << endl;
        if(umap.find(sum) == umap.end())
            umap[sum] = 1;
        else
            umap[sum]++;
    }
    
    sum = 0;
    
    for(int i=n2-1;i>=0;i--){
        temp = stack2[i];
        sum = sum + temp;
        if(umap.find(sum) == umap.end())
            umap[sum] = 1;
        else
            umap[sum]++;
    }
    
    sum = 0;
    
    for(int i=n3-1;i>=0;i--){
        temp = stack3[i];
        sum = sum + temp;
        if(umap.find(sum) == umap.end())
            umap[sum] = 1;
        else
            umap[sum]++;        
    }
    
    
    map <long,long> :: iterator it;
    int max_val = -INT_MAX;
    
    for(it = umap.begin() ;it != umap.end() ;it++){
        if(it->second == 3 && it->first >max_val)
            max_val = it->first;
            
    }
    
    if(max_val == -INT_MAX) //Incase no height matches
        cout << "0" << endl;
    else
        cout << max_val << endl;
    
    
    
    
    
}