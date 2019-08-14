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

ll t;
cin >> t;

while(t--){
	ll n;
	cin >> n;

	vector <ll> arr;

	f(i,0,n){
		ll num;
		cin >> num;
		arr.push_back(num);
	}

	map <ll,ll> l_map;
	map <ll,ll> :: iterator it;

	ll sum =0;
	l_map[0] = 0;

	f(i,0,n){
		sum += arr[i];
		l_map[sum] = i;
	}

	// for(it=l_map.begin(); it != l_map.end(); it++)
	// 	cout << it->first << " index is " << it->second << endl;

	ll r_sum =0;
	bool flag = false;

	if(n-l_map[0] == 1){
		cout << "YES" << endl;
		continue;
	}

	for(ll i=n-1;i>=0;i--){
		r_sum += arr[i];

		if(l_map.find(r_sum) != l_map.end()){
			if(i-l_map[r_sum] == 2){
				flag = true;
				break;
			} 
		}

	}

	if(!flag)
		cout << "NO" << endl;
	else
		cout << "YES" << endl;
}
	
}