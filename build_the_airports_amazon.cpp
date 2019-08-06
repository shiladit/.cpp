#include <bits/stdc++.h>
using namespace std;

int main() {

    int n;
    cin >> n;

    int arr[1440] = { 0 };

    bool turn = true;

    for(int i=0;i<2*n;i++){
        string t;
        cin >> t;

        int j ;
        for(j=0;j<t.length();j++){
            if(t[j] == ':')
                break;
        }

        string u = t.substr(0,j);
        string v = t.substr(j+1,4);

        long val = (stoi(u))*60;
        val = val + stoi(v);

        if(turn)
            arr[val] = 1;
        else if(!turn)
            arr[val+1] = -1;

        turn = !turn;

    }

    //Calc Cumulative Sum

    int sum = 0;
    int max_val = -INT_MAX;

    for(int i=0;i<1440;i++){
        sum = sum + arr[i];
        if(sum > max_val)
            max_val = sum;
    }

    cout << max_val << endl;
}