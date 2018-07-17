#include<bits/stdc++.h>

using namespace std;

int main() {
	int s1,x1,s2,x2;
	cin >> s1 >> x1 >> s2 >> x2;

	if(s1 < s2 && x2 > x1)
		cout << "NO\n" ;
	else if(x1 == x2 && s1 > s2 || x1 == x2 && s1 < s2)
		cout << "NO\n";
	else if((s2-s1)%(x2-x1)==0)
		cout << "YES\n";
	else 
		cout << "NO\n";

	return 0;

}