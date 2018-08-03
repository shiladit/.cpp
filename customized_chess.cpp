#include<bits/stdc++.h>

using namespace std;

int arr[100][100];

int main() {
    
    int t,N;
    cin >> t;

    while(t) {
    cin >> N;

    bool flag =1;

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin >> arr[i][j];
            if( i-1>=0 && (arr[i-1][j] == arr[i][j])) //Checking Top
                flag =0;
            if( j-1>=0 && (arr[i][j-1] == arr[i][j])){ // Checking Left
                flag =0;
            }
        }
    }

    if(!flag)
        cout << "No\n";
    else
        cout << "Yes\n";

    t--;
    }
}