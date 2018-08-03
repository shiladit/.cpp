#include<bits/stdc++.h>

using namespace std;

// O(nlogn) solution

vector <int> swap (vector <int> arr){

int i=1;
	while(i!= arr.size()) {
		int temp = arr[i+1];
		arr[i+1] = arr[i];
		arr[i] = temp;

		i=i+2;
	}

	return arr;
}


void print(vector <int> arr) {
	for(int i=0;i<arr.size();i++)
		cout << arr[i] << " ";

	cout << endl;
}



int main() {
	int size;
	cin >> size;
	int temp;

	vector <int> arr;

	for(int i=0;i<size;i++){
		cin >> temp;
		arr.push_back(temp);

	}

   sort(arr.begin(),arr.end());

   arr = swap(arr);

   print(arr);


}