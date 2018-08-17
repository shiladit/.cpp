/* https://www.geeksforgeeks.org/delete-middle-element-stack/ */

#include<bits/stdc++.h>

using namespace std;

stack <int> stk;
bool flag = false;

void remove_middle_element(int size){
	int val = -1;
	
	if(!stk.empty()){
		val = stk.top();
		stk.pop();
	}
	else
		return;

	remove_middle_element(size);


	if(stk.size() == size/2 && !stk.empty() && flag == false)
		flag = true ;
	else{
		stk.push(val);
	}

	if(stk.size() == size-1){

		while(!stk.empty()){
		int a= stk.top();
		cout << a << " ";
		stk.pop();
	}

	cout << endl;

	}
}


int main() {
	int size,temp;
	cin >> size;
	int org_size = size;

	while(size--){
		cin >> temp;
		stk.push(temp);
	}

	remove_middle_element(org_size);
	
}