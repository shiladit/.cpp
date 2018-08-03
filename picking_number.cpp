#include<bits/stdc++.h>

using namespace std;

int main() {
	int size;
	cin >> size;

	int arr[size];

	int max = 1;
	int count =1;


	for(int i=0;i<size;i++){
		cin >> arr[i];
	}

	for(int i=0;i<size;i++){
		if((arr[i] == arr[i+1]) || (arr[i] == arr[i+1]-1) || (arr[i] == arr[i+1]+1))
			count++;
		else
			count=1;

		if(count > max)
			max = count;
	}


	cout << max << endl;
}