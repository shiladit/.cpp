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

	ll k;
	cin >> k;

	while(k--){

	string s,p;
	cin >> s;
	p = s;
	reverse(p.begin(),p.end());
	// cout << s << " --> " << p << endl;

	bool flag = false;

	f(i,1,s.length()-1){
		if(abs(s[i]-s[i-1]) != abs(p[i]-p[i-1])){
			flag = true;
			break;
		}
	}

	if(flag)
		cout << "Not Funny" << endl;
	else
		cout << "Funny" << endl;

	}
}