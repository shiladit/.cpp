#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main(){

	int n,m,k;
	cin >> n >> m >> k;

	vector <pair <ll,ll> > bikers;
	vector <pair <ll,ll> > bikes;

	priority_queue <ll,vector <ll>, greater <ll> > pq;

	for(int i=0;i<n;i++){
		ll x,y;
		cin >> x >> y;
		bikers.push_back(make_pair(x,y));
	}

	for(int i=0;i<m;i++){
		ll x,y;
		cin >> x >> y;
		bikes.push_back(make_pair(x,y));
	}

	for(int i=0;i<bikers.size();i++)
		for(int j=0;j<bikes.size();j++){
			ll dist = max(abs(bikers[i].first-bikes[i].first),abs(bikers[i].second-bikes[i].second));
			pq.push(dist);
		}

	int max_val = -INT_MAX;
	// set <ll> s;

	// while(s.size() != k){
	// 	ll val = pq.top();
	// 	s.insert(val);
	// 	pq.pop();

	// }

	// set <ll> :: iterator it;

	// for(it=s.begin(); it!=s.end(); it++){
	// 	if(*it>max_val)
	// 		max_val = *it;
	// }

	// cout << max_val*max_val << endl;

	while(!pq.empty()){
		cout << pq.top() << " ";
		pq.pop();
	}

	cout << endl;

}