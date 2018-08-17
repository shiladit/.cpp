/* https://www.geeksforgeeks.org/searching-array-adjacent-differ-k/ */

#include<bits/stdc++.h>

using namespace std;

int main() {

	int size,temp,k,elem_to_search;
	cin >> size >> k;

	vector <int> arr;

	while(size--){
		cin >> temp;
		arr.push_back(temp);
	}

	cin >> elem_to_search;

	int i;
	
	for(i=0;i<arr.size();i++){
		if(arr[i] == elem_to_search)
			break;
		else {
			int step = abs(arr[i]-elem_to_search)/k;
			i= i+step; 
		} 

	}

	if(i >= arr.size())
		cout << "Not Found\n";
	else
		cout << i << endl;


}