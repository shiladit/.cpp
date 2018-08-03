#include<bits/stdc++.h>

using namespace std;

int main() {
	int T;
	cin >> T;

	while(T) {
	int size,temp;
	cin >> size;

	vector <int> arr;

	for(int i=0;i<size;i++){
		cin >> temp;
		arr.push_back(temp);
	}
	int m;
	cin >> m;

	sort(arr.begin(),arr.end());

	int i=1;
	int j=m;

	int max_diff = (abs(arr[0]-arr[m-1]));
	// cout << max_diff << endl;

	while(j != arr.size()){
		
		int diff = abs(arr[i] - arr[j]);

		if(diff < max_diff)
			max_diff = diff;

		i++;
		j++;


	}

	cout << max_diff << endl;

	T--;
	}


}