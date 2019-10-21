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

ll n;
cin >> n; // No of cities

vector <ll> popu;

for(int i=0;i<n;i++){
	ll x;
	cin >> x;
	popu.push_back(x);
}

vector <ll> towns;

for(int i=0;i<n;i++){
	ll x;
	cin >> x;
	towns.push_back(x);
}

ll m;
cin >> m; // No of clouds

vector <ll> clouds;

for(int i=0;i<m;i++){
	ll x;
	cin >> x;
	clouds.push_back(x);
}

vector <ll> range;

map <ll,ll> map1;

for(int i=0;i<m;i++){
	ll x;
	cin >> x;
	range.push_back(x);
	ll l_range = clouds[i]-x;
	ll r_range = clouds[i]+x;

	map1[l_range] += 1;
	map1[r_range+1] -= 1; 
}

map <ll,ll> :: iterator it;

for(it = map1.begin(); it != map1.end(); it++)
	cout << it->first << " --> " << it->second << endl;

ll sum =0;

for(it = map1.begin(); it != map1.end(); it++){
	sum = sum + it->second;
	map1[it->first] = sum ;
}

cout << "\n\nAfter Cumulative Sum\n\n";

for(it = map1.begin(); it != map1.end(); it++)
	cout << it->first << " --> " << it->second << endl;

vector <pair <ll,ll> >  selected_towns;
map <ll,ll> :: iterator it1;
map <ll,ll> :: iterator it2;

for(int i=0;i<towns.size();i++){
	if(map1.find(towns[i]) == map1.end()){
		cout << "\nTOWN IS AT: " << towns[i] << " ";
		it1 = map1.upper_bound(towns[i]);
		it2 = map1.lower_bound(towns[i]);
		it2--;
		cout << "Upper Bound is: " << it1->first << " -- " << "Lower Bound is: " << it2->first << endl;
		if(it1->second == 1 || it2->second == 1)
			selected_towns.push_back(make_pair(towns[i],popu[i]));
	}
	else{
		cout << "Bound is: " << map1[towns[i]] << endl;
		if(map1[towns[i]] == 1)
			selected_towns.push_back(make_pair(towns[i],popu[i]));
	}
}

if(selected_towns.size() == 0)
	cout << "0" << endl;  // Every city is under atleast 2 clouds
else{

}

 	
}