#include <bits/stdc++.h>

using namespace std;

int main() {
	string s;
	cin >> s;

	int len = s.length();

	int i= 0;
	int j= len-1;

	while(i < j){
		swap(s[i],s[j]);
		i++;
		j--;

	}

	cout << s << endl;
}