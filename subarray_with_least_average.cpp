/* https://www.geeksforgeeks.org/find-subarray-least-average/ */

#include <bits/stdc++.h>

using namespace std;

int main() {
	int size,temp,k;

	cin >> size >> k;
	vector <int> arr;

	while(size--){
		cin >> temp;
		arr.push_back(temp);
	}

	float avg = -1;
	float sum = 0;

	for(int i=0;i<k;i++)
		sum = sum+arr[i];

	avg = sum/k;

	float min_avg = avg;

	int left = -1;
	int right = -1;

	for(int i=k;i<arr.size();i++){
		sum = sum - arr[i-k] + arr[i];
		// cout << sum << " " <<  i-k << " " <<  i <<  endl;
		avg = sum/k;

		if(min_avg>avg){
			left = i-k+1;
			right= i;
			min_avg = avg;
		}
	}
	
	cout << left << " " << right << endl;
}	