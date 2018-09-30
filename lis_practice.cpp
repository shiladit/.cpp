#include<bits/stdc++.h>

using namespace std;

int main() {

	int t;
	cin >> t;

	while(t--){
	int size;

	cin >> size;

	vector <int> arr;
	int temp;

	for(int i=0;i<size;i++){
		cin >> temp;
		arr.push_back(temp);
	}

	vector <int> aux(size,1);

	int i=0;
	int j=1;

	while(j<size){
		if(arr[i] < arr[j]){
			aux[j] = aux[i]+1;
			i=j;
			j=i+1; 
		}
		else{
			aux[j]=aux[i];
			j++;

		}

	}

	cout << aux[size-1] << endl;
}
}