//shiladitya
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
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

bool compare(pair <ll,ll> &a, pair <ll,ll> &b){
	if(a.first > b.first)
		return true;
	else
		return false;
}

int main(){

ll q;
cin >> q;

while(q--){
	ll n;
	cin >> n;

	vector <pair <ll,ll> > arr;

	f(i,0,n){
		ll x;
		cin >> x;
		arr.push_back(make_pair(x,i));
	}

	sort(arr.begin(),arr.end(),compare);

	ll i=0;
	ll j=n-1;
	ll k =0;

	bool turn = 0; //ANDY

	while(i<=j){

		while(arr[k].second > j)
			k++;

		ll max_val = arr[k].first;
		j = arr[k].second - 1;
		k++;

		// cout << max_val << " --> " << "New j is: " << j << endl;

		turn = !turn;	
	}

	if(turn)
		cout << "BOB\n";
	else
		cout << "ANDY\n"; 
}
	
}