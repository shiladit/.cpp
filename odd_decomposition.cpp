#include <bits/stdc++.h>
using namespace std;

int main() {
	long n;
	cin >> n;

	int sum = 0;
	for(int i=1;i<=n;i=i+2){
		sum += i;
		if(sum > n)
			break;
	}

	if((sum - n)%2 == 1) // ODD
	{
		int rem = sum-n;

		int new_sum =0;
		int i = 1;
		while(new_sum != n){

			if(i != rem){
				new_sum += i;
				cout << i << " ";
			}
			
			i=i+2; 
		}
	}
	else {
		int rem = sum-n;
		rem = rem - 1;

		int i =3;
		int new_sum = 0;
		
		while(new_sum != n){
			if(i != rem){
				new_sum += i;
				cout << i << " ";
			}
			i = i+2;
		}

	}

	cout << endl;
	// cout << sum << endl;

}