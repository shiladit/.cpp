#include<bits/stdc++.h>

using namespace std;

void calculate_leader(int arr[],int size){
	int i=0;
	int j=1;

	while(i != (size-2) || j != (size-1)) {
		if(arr[i]<arr[j]){
			i=j;
			j++;
		}
		else{
			i++;
			j++;
		}
	}


	// for(int i=0;i<size;i++)
	// 	cout << arr[i] <<  " ";

	cout << i << " " << arr[i] << endl;

	// return arr[i];
}

int main() {

	int T;
	cin >> T;

	while(T) {
		int size;
		cin >> size;
		int arr[size];

		for(int i=0;i<size;i++)
			cin >> arr[i];

		calculate_leader(arr,size);

		// cout << leader << endl;

		T--;
	}


	return 0;
}