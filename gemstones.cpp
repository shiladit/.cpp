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
	ll no;
	cin >> no;
	ll n = no;

	vi arr(26,0);

	while(no--){
		string s;
		cin >> s;

		set <char> dic;

		f(i,0,s.length()){
			dic.insert(s[i]);
		}

		set <char> :: iterator it;

		for(it = dic.begin();it !=dic.end(); it++){
			arr[*it - 'a']++;
		}

		dic.clear();
	}

	ll count =0;

	f(i,0,26){
		if(arr[i] == n)
			count++;
	}

	cout << count << endl;
}