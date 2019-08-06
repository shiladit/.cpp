#include <bits/stdc++.h>
#define ll long long

using namespace std;

bool compare(pair <ll,ll> a, pair <ll,ll> b){
	if(a.second > b.second)
		return true;
	else 
		return false;
}

void print_func(vector <pair <ll,ll> > p){
	for(int i=0;i<p.size();i++){
		pair <ll,ll> x = p[i];
		cout << x.first << " -- " << x.second << " || "; 
	}

	cout << endl;
}

int main() {
	ll n;
	cin >> n;

	vector <ll> pop;

	for(ll i=0;i<n;i++){
		ll p;
		cin >> p;
		pop.push_back(p);
	}	

	vector <ll> cities;

	ll max_cord = -INT_MAX;
	ll min_cord = INT_MAX;

	for(ll i=0;i<n;i++){
		ll p;
		cin >> p;

		if(p > max_cord)
			max_cord = p;

		if(p < min_cord)
			min_cord = p;

		cities.push_back(p);
	}

	vector <ll> total_pop(max_cord+1,0);

	for(ll  i=0;i<max_cord+1;i++){
		total_pop[cities[i]] += pop[i];
	}

	vector <pair <ll,ll> > highest_pop;

	for(ll i=0;i<max_cord+1;i++){
		highest_pop.push_back(make_pair(i,total_pop[i]));
	}

	sort(highest_pop.begin(),highest_pop.end(),compare);

	// print_func(highest_pop);

	/* Print */

	// for(ll i=0;i<n+10;i++){
	// 	cout << total_pop[i] << " ";
	// }

	// cout << endl;

	ll m;
	cin >> m;

	vector <ll> cloud;

	for(ll i=0;i<m;i++){
		ll p;
		cin >> p;
		cloud.push_back(p);
	}

	vector <ll> range(max_cord+1,0);

	// cout << min_cord << " !!! " << max_cord << endl;

	for(ll i=0;i<m;i++){
		ll p;
		cin >> p;

		ll l_range = cloud[i]-p;
		ll r_range = cloud[i]+p;

		// cout << l_range << " -- " << r_range << endl;

		if(l_range < 0)
			range[0] += 1;

		if(r_range > max_cord)
			range[max_cord+1] += -1;

		if(l_range >=0)
			range[l_range] += 1;

		if(r_range <=max_cord)
			range[r_range+1] += -1;

	}

	// for(ll i=0;i<=n+10;i++){
	// 	cout << range[i] << " ";
	// }

	// cout << endl;

	/* Calculate Presum */

	for(ll i=1;i<max_cord+1;i++){
		range[i] = range[i] + range[i-1];
	}

	


}