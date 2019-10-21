//shiladitya
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#define ll long long
#define f(i,a,b) for(ll i=a;i<b;i++)
#define mod (1000*1000*1000+7)
#define vi vector < int >
#define vb vector < bool >
#define vl vector < ll >
#define vvi vector < vector <int> >
#define vvc vector < vector <char> > 
#define pqueue priority_queue< int >
#define pdqueue priority_queue< int,vi ,greater< int > >

using namespace std;

int main(){

	ll t;
	cin >> t;

	while(t--){
		ll n;
		cin >> n;

		ll sum =0;

		map <ll,ll> map1;

		for(int i=1;i<=n;i++){
			sum = sum^i;
			cout << i << " pile's nim_sum is: " << sum << endl;
			if(map1.find(sum) == map1.end()){
				map1[sum] = i;
			}
		}

	}
	
}