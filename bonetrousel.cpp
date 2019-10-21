//shiladitya
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
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

int t;
cin >> t;

while(t--){
	ll n,k,b;
	cin >> n >> k >> b;

	ll lower_lim = (b*(b+1))/2;
	ll upper_lim = (b*(2*k-b+1))/2;

	// set <int> s;

	// ll cum_sum = 0;
	// for(int i=0;i<=k;i++){
	// 	cum_sum += i;
	// 	s.insert(cum_sum);
	// }

	ll diff = n;

	if(n < lower_lim || n > upper_lim){
		cout << "-1" << endl;
		break;
	}


}

}