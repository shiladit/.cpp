#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;


stack <int> s1;

void enqueue(int x){
	s1.push(x);
}

void dequeue() {
	stack <int> s2 ;
	while(s1.empty() != 1){
		int val = s1.top();
		s2.push(val);
		s1.pop();
	}

	s2.pop(); //Removing the front of the queue

	while(s2.empty() != 1){
		int val = s2.top();
		s2.pop();
		s1.push(val);
	}
}

void print_front(){
	vector <int> arr;
	int val;
	while(s1.empty() != 1){
		val = s1.top();
		arr.push_back(val);
		s1.pop();
	}

	cout << val << endl;

	for(int i= arr.size()-1;i >-1 ;i--)
		s1.push(arr[i]); 
	

}

int main() {
    int q; // No of queries
    cin >> q;
    
    while(q) {
    	int a,b;
    	cin >> a;
    	if(a ==1) {
    		cin >> b;
    		enqueue(b);
    	}
    	else if(a== 2)
    		dequeue();
    	else 
    		print_front();

    	q--;
    }
    return 0;
}


