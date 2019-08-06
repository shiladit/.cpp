//shiladitya
#include <bits/stdc++.h>
#define ll long long
#define f(i,a,b) for(ll i=a;i<b;i++)
#define pb push_back
#define mp make_pair
#define mod (1000*1000*1000+7)
#define vi vector < int >
#define vl vector < ll >
#define pqueue priority_queue< int >
#define pdqueue priority_queue< int,vi ,greater< int > >

using namespace std;

int main() {
    ll len;
    cin >> len;

    string s;
    cin >> s;

    ll count = 0;

    ll i =2;

    while(i<len){
        if((int)s[i-2] == '0' && (int)s[i-1] == '1' && (int)s[i] == '0'){
            count++;
            i = i+3;
        }
        else
            i++;
    }

    cout << count << endl;
}