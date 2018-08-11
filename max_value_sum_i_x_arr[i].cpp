/*https://www.geeksforgeeks.org/find-maximum-value-of-sum-iarri-with-only-rotations-on-given-array-allowed/

Time Complexity = O(n)
*/
#include<bits/stdc++.h>

using namespace std;

int calculate_max_sum(vector <int> arr){
	int count=1;
	int max_sum =0;
	int arr_sum =0;
	for(int i=0;i<arr.size();i++){
		max_sum = max_sum + i*arr[i];
		arr_sum = arr_sum + arr[i];
	}


    int sum = max_sum;

	while(count != arr.size()){
		sum = sum + arr_sum - (arr.size()*arr[arr.size()-count]);

		if(sum > max_sum)
			max_sum = sum;

		count++;

	}

	return max_sum;
}


int main() {

	int size,temp;
	cin >> size;

	vector <int> arr;

	for(int i=0;i<size;i++){
		cin >> temp;
		arr.push_back(temp);
	}

	cout << calculate_max_sum(arr) << endl;
}


