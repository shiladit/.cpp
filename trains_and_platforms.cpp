#include <bits/stdc++.h>
using namespace std;

int main() {

    int n;
    cin >> n;

    int arr[3000] = { 0 };
    bool turn = true;
    
    for(int i=0;i<2*n;i++){
        int a;
        cin >> a;
        
        if(turn)
            arr[a] += 1;
        else
            arr[a+1] += -1;
        
        turn = !turn;
    }

    //Calc Cumulative Sum

    int sum = 0;
    int max_val = -INT_MAX;

    for(int i=0;i<3000;i++){
        sum = sum + arr[i];
        if(sum > max_val)
            max_val = sum;
    }

    cout << max_val << endl;
}