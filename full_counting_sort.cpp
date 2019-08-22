//shiladitya
#include <iostream>
#include <string>
#include <vector>

#define ll long long
#define f(i,a,b) for(ll i=a;i<b;i++)

using namespace std;

int main() {
    
    ll n, half;
    cin >> n;

    half = n/2;

    vector <vector <string> > arr(101);

    f(i,0,n){
        ll val;
        string s;

        cin >> val >> s;

        if(i < half){
            arr[val].push_back("-");
        }
        else
            arr[val].push_back(s);    
    }

    f(i,0,101){
        for(ll j=0;j < arr[i].size();j++){
            cout << arr[i][j] << " ";
        }
    }

    cout << endl;
}