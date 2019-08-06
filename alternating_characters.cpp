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

	int q;
	cin >> q;

	while(q--){

		string s;
		cin >> s;

		int i=0;
		int j=i+1;
		int count =0;

		while(j != s.length()){
			if(s[i] == s[j]){
				s.erase(s.begin()+i,s.begin()+i+1);
				count++;
			}
			else{
				i++;
				j++;
			}

			// cout << s << endl;
		}

		cout << count << endl;
	}

	return 0;
}