/* https://practice.geeksforgeeks.org/problems/longest-valid-parentheses/0 */

#include <bits/stdc++.h>

using namespace std;

int main() {
	string s;

	cin >> s;

	stack <char> stk;
	stk.push(-1);

	int i=0;
	
	int count=0;

	while(i != s.length()){

		if(s[i] == '(')
			stk.push(s[i]);
		
		else if(s[i] == ')'){

			if(stk.top() != -1){
				char temp = stk.top();
				if(temp == '('){
					stk.pop();
					count = count+2;
				}
			}
			
		}
		i++;

	}

	cout << count << endl;

}