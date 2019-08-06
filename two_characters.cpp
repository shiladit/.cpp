#include <bits/stdc++.h>

using namespace std;

bool check_valid(string t){
	for(int i=0;i<t.length()-2;i++)
		if(t[i] != t[i+2])
			return false;

	return true;	
}

int main() {

int len,max_len= 0;
cin >> len;

string s;
cin >> s;

set <char> uset;
set <char> :: iterator it;
set <char> :: iterator ut;

for(int i=0;i<s.length();i++){
	uset.insert(s[i]);
}

if(uset.size() <= 1)
	cout << "0" << endl;
else{
	for(it = uset.begin();it !=uset.end();it++)
		for(ut = uset.begin(); ut != uset.end(); ut++){
			if(it != ut){
				string t;
				for(int i=0;i<s.length();i++){
					if((*it == s[i]) || (*ut == s[i]))
						t = t + s[i];
				}
				if(check_valid(t) && t.length() > max_len){
						max_len = t.length();
						// cout << t << endl;
					}
				
			}
		}
		cout << max_len << endl;
}


}