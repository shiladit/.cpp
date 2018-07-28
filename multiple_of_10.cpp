#include<bits/stdc++.h>

using namespace std;


// Rounding off a number to its nearest multiple of 10

int main() {
	int n;
	cin >> n;

	int a = (n/10)*10;
	int b = n%10;
	if(b >5){
	    a = a+10; 
	}

	cout << a << endl;
}