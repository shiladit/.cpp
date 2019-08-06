#include <bits/stdc++.h>
#define ll long long
#define f(i,a,b) for(ll i=a;i<b;i++)

using namespace std;

int main() {
	string s,p;
	cin >> s;
	ll shift;
	cin >> shift;

	f(i,0,s.length()){
		if(int(s[i]) >=65 && int(s[i]) <=90){
			char x = char(((int(s[i] - 65)+shift)%26)+65)
			p = p + x;
		}
		else if(int(s[i]) >=97 && int(s[i]) <=122){

			// cout << char(((int(s[i] - 97)+shift)%26)+97) << endl;
			char x = char(((int(s[i] - 97)+shift)%26)+97);
			p = p + x;
		}
		else
			p = p + s[i];
	}

	cout << p << endl;

}