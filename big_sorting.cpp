//shiladitya
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#define ll long long
#define f(i,a,b) for(ll i=a;i<b;i++)

using namespace std;

bool compare(string s1,string s2){
    int l1 = s1.length();
    int l2 = s2.length();

    if(l1 == l2)
        return s1<s2;
    else 
        return l1<l2;
}

int main(){
    ll n;
    cin >> n;

    vector <string> arr(n);

    for(int i=0;i<n;i++)
        cin >> arr[i];

    sort(arr.begin(),arr.end(),compare);

    for(int i=0;i<n;i++)
        cout << arr[i] << endl; 
}
