/* https://www.geeksforgeeks.org/count-pairs-difference-equal-k/ */

#include <bits/stdc++.h>

using namespace std;

bool binary_search(vector <int> arr,int val,int low,int high){

	int mid = low+high/2;

	if(low < high){

	if(val == arr[mid])
		return true;

	if(val < arr[mid])
		binary_search(arr,val,low,mid);

	if(val > arr[mid])
		binary_search(arr,val,mid+1,high);
	}

	return false;


}

int main() {

	int size,temp,k;

	cin >> size >> k;

	vector <int> arr;

	while(size--){
		cin >> temp;
		arr.push_back(temp);
	}

	sort(arr.begin(),arr.end());

	int count =0 ;

	for(int i=0;i<arr.size();i++){
		if(binary_search(arr,arr[i]+k,i+1,arr.size()) == true)
			count++;
	}

	cout << count << endl;
}