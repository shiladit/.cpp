#include<bits/stdc++.h>

using namespace std;

int main() {
	int T;

	cin >> T;

	while(T) {

		string s;
		cin >> s;

		int len =s.length();

		stack <string> stk;

		int i=0;
		while(i != s.length()){
			string new_s;
			while( s[i] != '.' ){
				
				new_s.append(s,i,1);
				i++;
			}
			
			stk.push(new_s); 
			i++;
		}

		while(!stk.empty()){
			string s1 = stk.top();
			stk.pop();
			cout << s1 << "." ;  
		}
		cout << endl;


		T--;

	} 
	

	return 0;
}