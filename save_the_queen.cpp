#include <bits/stdc++.h>
#define ll long double
#define SET_NO 300

using namespace std;

int main() {
    ll n,k;
    cin >> n >> k;

    vector <ll> arr;
    for(ll i=0;i<k;i++){
        ll x; 
        cin >> x;
        arr.push_back(x);
    }

    ll low = 0;
    ll high = INT_MAX;
    ll mid;

    for(ll i=0;i<SET_NO;i++){
        ll soldiers = n;

        mid = (low+high)/2;  //using binary search on the time axis
        
        ll req =0;

        for(ll j=0;j<k;j++){
            if(arr[j] > mid)
                soldiers--;
            else{
                req = req + arr[j];
            }
        }

        if(soldiers <= 0){
            low = mid;    
            continue;
        }

        req = req / soldiers;

        if(req < mid)
            high= mid;
        else
            low = mid;
         
    }

    cout << fixed << setprecision(9) << mid << endl;
}
