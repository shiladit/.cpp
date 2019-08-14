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

ll n, k;
cin >> n >> k;

vector <ll> arr;

f(i,0,n){
	ll x;
	cin >> x;
	arr.push_back(x);
}

sort(arr.begin(),arr.end(),greater <int>());


int num_of_transmitters=0;

int i=0;
while(i<n){
	num_of_transmitters++;
	int max_val = arr[i];
	int j = i+1;
	while(j < n && (arr[j]+k >= max_val)){
		j++;
	}
	i= j-1;
	max_val = arr[i];
	while(j<n && (arr[j]+k >= max_val)){
		j++;
	}
	i=j;
}

cout << num_of_transmitters << endl;

	
}
