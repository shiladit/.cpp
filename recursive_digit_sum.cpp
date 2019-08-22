//shiladitya
#include <bits/stdc++.h>
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

ll cal_sum(string s,ll i,ll j){
	j=j-1;

	if(i<=j){
		return (ll)(s[j]-'0') + cal_sum(s,i,j);
	}
	else
		return 0;
}

ll cal_int_sum(ll n){

    if(n == 0)
        return 0;
    else
        return n%10 + cal_int_sum(n/10);
}

int main(){
	string n;
	ll k;

	cin >> n >> k;

	ll m = cal_sum(n,0,n.length()) ;

	cout << m << endl;
	
	m = m *k;

	while(m/10 != 0){
		m = cal_int_sum(m);
	}

	cout << m << endl;
}