#include <bits/stdc++.h>
using namespace std;

int main() {
	int size,x;
	cin >> size;
	vector <int> arr;

	for(int i=0;i<size;i++){
		cin >> x;
		arr.push_back(x);
	}

	sort(arr.begin(),arr.end());

	int count = 0;

	for(int i=0;i<arr.size();){
		int range = arr[i] + 4;
		// cout << arr[i] <<  " -- " << range << endl;
		count++;

		while(arr[i] <= range){
			if(i >= arr.size())
				break;
			
			i++;
		}

		// cout << i << " -- " << count  << endl;
	}

	cout << count << endl;
}