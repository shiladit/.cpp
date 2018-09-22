#include <bits/stdc++.h>

using namespace std;

int main() {
	string s1 ="qwewerrty";
	string s2 = "wer" ;
	// cin >> s1;
	// cin >> s2;

	while(1){
			int pos = s1.find(s2);
			if(pos >= 0)
			s1.erase(pos,s2.length());
			else
				break;
		
	}
	cout << s1 << endl;
}