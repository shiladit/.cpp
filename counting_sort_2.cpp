#include <bits/stdc++.h>

using namespace std;

int arr[105];

int main() {
    int size,temp;
    cin >> size;
    
    for(int i=0;i<size;i++){
        cin >> temp;
        arr[temp]++;
    }
    
    for(int i=0;i<100;i++){
        int range= arr[i];
        for(int j=0;j<range;j++)
            cout << i << " ";
    }
        
    
    cout << endl;
}