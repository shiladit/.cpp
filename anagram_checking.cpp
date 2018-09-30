#include <bits/stdc++.h>

using namespace std;

bool compare(string s,string t){

	sort(s.begin(),s.end());
	sort(t.begin(),t.end());

	if(s==t)
		return true;
	else
		return false;
}

int main() {
	string s,t;

	cin >> s >> t;

	if(compare(s,t))
		cout << "YES\n";
	else
		cout << "NO\n";
}