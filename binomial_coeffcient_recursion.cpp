#include <bits/stdc++.h>

using namespace std;

int find_coeff(int n,int k){
	if(k==0)
		return 1;
	else if(k==1)
		return n;
	else if(n==k)
		return 1;

	else
		return find_coeff(n-1,k-1)+find_coeff(n-1,k);
}


int main() {
	int n,k;
	cin >> n >> k;
	cout << find_coeff(n,k);
	cout << endl;
}