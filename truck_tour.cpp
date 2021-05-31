//shiladitya
#include <iostream>
#define ll long long

using namespace std;

int main() {
    ll n;
    cin >> n;

    ll amt_of_pet = 0,dist = 0;
    ll index = -1;

    for(int i=0;i<n;i++){
        ll amt;
        cin >> amt >> dist;
        amt_of_pet += amt;
        if(amt_of_pet-dist < 0){
            amt_of_pet = 0;
            dist = 0;
            index = i;
        }
        else{
            amt_of_pet = amt_of_pet - dist;
        }
    }
    cout << ++index << endl;
}