#include <bits/stdc++.h>

using namespace std;

int main() {
    
    long n,k,temp;
    cin >> n;
    cin >> k;
    
    vector <long> arr;
    
    for(long i=0;i<n;i++){
        cin >> temp;
        arr.push_back(temp);
    }
    
    sort(arr.begin(),arr.end());

    //PRINT
    // for(int i=0;i<arr.size();i++)
    //     cout << arr[i] << " ";

    // cout << endl;
    
    int min = INT_MAX;
   
   int i=0;
   int j= k-1; 
   while(j != arr.size()){
        if(abs(arr[i]-arr[j]) < min)
            min = abs(arr[i]-arr[j]);

        i++;j++;
   
   }

   cout << min << endl;


}