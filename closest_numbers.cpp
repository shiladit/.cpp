#include <bits/stdc++.h>

using namespace std;

int main() {
    long size,temp;
    cin >> size;
    
    vector <long> arr;
    
    for(int i=0;i<size;i++){
        cin >> temp;
        arr.push_back(temp);
    }
    
    sort(arr.begin(),arr.end());
    
    vector <long> index;
    
    int i=0;
    int j=1;
    
    int min= INT_MAX;
    
    for(i=0,j=1;j<arr.size();i++,j++){
        if(arr[j]-arr[i] < min){
            min = arr[j]-arr[i];
            index.erase(index.begin(),index.end());
            index.push_back(arr[i]);
            index.push_back(arr[j]);
        }
        else if (arr[j]-arr[i] == min){
            index.push_back(arr[i]);
            index.push_back(arr[j]);
        }
                   
    }
    
    for(int i=0;i<index.size();i++)
        cout << index[i] << " ";
    
    cout << endl;
}