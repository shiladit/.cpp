/* https://www.geeksforgeeks.org/sort-stack-using-temporary-stack/ */

#include <bits/stdc++.h>

using namespace std;

void print_stack(stack <long> stk){
	while(!stk.empty()){
		cout << stk.top() << " ";
		stk.pop();
	}

	cout << endl;
}

int main() {
	
	long size,temp;
	cin >> size;

	stack <long> stk1;
	stack <long> stk2; // Stores sorted sequence

	while(size--){
		cin >> temp;
		stk1.push(temp);
	}

	while(!stk1.empty()){
		int temp = stk1.top();
		stk1.pop();

		while(!stk2.empty() && stk2.top()>temp){
			stk1.push(stk2.top());
			stk2.pop();
		}

		stk2.push(temp);
		
	}

	print_stack(stk2);

}

