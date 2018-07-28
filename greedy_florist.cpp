#include<bits/stdc++.h>

using namespace std;

int main() {
    int n,k,temp;
    cin >> n >> k;
    
    vector <int> arr;
    
    for(int i=0;i<n;i++){
        cin >> temp;
        arr.push_back(temp);
    }
    
    sort(arr.begin(),arr.end(),greater<int>());
    
    long sum=0;
    int lower =0;
    int j=1;
    int i;
    
    while(lower != arr.size()){
    for(i=lower;i<lower+k && (i != arr.size());i++){
        sum = sum + j*arr[i];
        }
    lower = i;
    j++;
    }
    
    cout << sum << endl;
    
}