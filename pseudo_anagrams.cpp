#include <bits/stdc++.h>

using namespace std;

bool check_pseudo_anagrams(string s1,string s2){
	set <char> s;


	for(int i=0;i<s1.length();i++){
		s.insert(tolower(s1[i]));
	}

	for(int i=0;i<s2.length();i++){
		char c = tolower(s2[i]);
		if(s.find(c) == s.end())
			return false;
	}

	return true;
}

int main() {

	string s1,s2;

	cin >> s1;
	cin >> s2;

	if(check_pseudo_anagrams(s1,s2))
		cout << "YES\n";
	else
		cout << "NO\n";
}