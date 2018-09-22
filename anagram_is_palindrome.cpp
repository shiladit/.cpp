#include <bits/stdc++.h>

using namespace std;

int main() {

	string s;

	cin >> s;

	vector <char> arr(26,0);

	for(int i=0;i<s.length();i++){
		int val = tolower(s[i]) - 'a';
		
		arr[val]++;
	}

	int odd_count =0;

	for(int i=0;i<arr.size();i++){
		if(arr[i]%2 ==1)
			odd_count++;
	}

	if(odd_count > 1)
		cout << "NOT POSSIBLE\n";
	else
		cout << "POSSIBLE\n";
}