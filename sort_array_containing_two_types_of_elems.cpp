/* https://www.geeksforgeeks.org/sort-array-containing-two-types-elements/ */

#include <bits/stdc++.h>

using namespace std;

int main() {
	int size,temp;
	cin >> size;

	vector <int> arr;


	while(size--){
		cin >> temp;
		arr.push_back(temp);
	}

	int i=0;
	int j=arr.size()-1;

	while(i<j){
		if(arr[i] > arr[j]){
			int temp = arr[i];
			arr[i] = arr[j];
			arr[j]= temp;
			i++;
		}
	
		else if(arr[i] == arr[j])
				i++;
		else
			j--;

	}

	for(int i=0;i<arr.size();i++)
		cout << arr[i] << " ";

	cout << endl;
}