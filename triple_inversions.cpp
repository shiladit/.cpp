#include <bits/stdc++.h>
using namespace std;

#define size 5

int main() {
	int arr[size] = {5,4,3,2,1};

	vector <int> result;

	for(int i=0;i<size;i++){
		int count =0;
		for(int j=i+1;j<size;j++){
			if(arr[j]<arr[i])
				count++;
		}
		result.push_back(count);
	}

	for(int i=0;i<size;i++){
		int sum =0;
		for(int j=i+1;j<size;j++){
			if(arr[i]>arr[j])
				sum = sum+result[j];
		}
		result[i]= sum ;
	}

	// for(int i=0;i<result.size();i++)
	// 	cout << result[i] << " ";

	// cout << endl;

	int total_sum=0;

	for(int i=0;i<size;i++)
		total_sum += result[i];

	cout << total_sum << endl;
}