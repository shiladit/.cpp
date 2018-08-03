#include<bits/stdc++.h>

using namespace std;

long long int fib(long n,long first,long second){
	if (n ==first) 
		return 0;
	if( n ==second)
		return 1;

	return (fib(n-1,first,second)*fib(n-1,first,second)) + fib(n-2,first,second);

}

int main() {
	
	long first,second, n;
	

	
	cin >> first >> second >> n;

	cout << fib(n-1,first,second) << endl;

}