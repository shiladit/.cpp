#include <bits/stdc++.h>

using namespace std;

int arr[101];

int main() {
    long size,temp;
    cin >> size;
    
    long count = 0;
    
    while(size--){
        
        cin >> temp;
        arr[temp] = arr[temp]+1;
        if(arr[temp] % 2 == 0)
            count++;
    }
    
    cout << count << endl;
    
}