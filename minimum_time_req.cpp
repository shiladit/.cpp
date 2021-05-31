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

	ll n,goal;
	cin >> n >> goal;

	vector <ll> arr(n);

	for(long i=0;i<n;i++)
		cin >> arr[i];
	
	ll l_limit = 0;
	ll u_limit = 100000000000000;

	bool satisfied = false;

	ll med = -1;

	while(!satisfied){

		if(u_limit > l_limit)
			med = (l_limit+u_limit-1)/2;
		else{
			satisfied = true;
			continue;
		}

		long iteration_count  = 0;

		for(long i=0;i<n;i++)
			iteration_count += med/arr[i];
		if(iteration_count == goal)
			satisfied = true;
		else if(iteration_count > goal)
			u_limit = med;
		
		else if(iteration_count < goal)
			l_limit = med+1;
		
		else
			;
	}

	/* After finding approximate range, we check within +5 and -5 bounds of the range to see what satisfies */

	for(long i=(med+5);i>(med-5);i--){
		long iteration_count  = 0;

		for(long j=0;j<n;j++)
			iteration_count += i/arr[j];

		if(iteration_count >= goal && i<(med+5))
			med = i;
	}

	cout << med << endl;
}