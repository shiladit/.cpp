#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin >> n;

	int arr[n];

	for(int i=0;i<n;i++){
		cin >> arr[i];
	}

	long sum = 0;

	for(int i=0;i<n;i++){ //pivot
		for(int j=i+1;j<n;j++){
			int or_sum = 0;
			for(int k=i;k<=j;k++)
				or_sum = or_sum | arr[k];

			// cout << i << " -- " << j << "             == " <<  or_sum << endl;
			sum = sum + or_sum;
		}
	}

	for(int i=0;i<n;i++){
		sum = sum + arr[i];
	}


	cout << sum << endl;
}