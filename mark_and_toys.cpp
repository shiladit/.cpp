#include <bits/stdc++.h>

using namespace std;

int main() {
	long n,k,temp;

	cin >> n >> k;

	vector <long> arr;

	for(long i=0;i<n;i++){
		cin >> temp;
		arr.push_back(temp);

	}

	sort(arr.begin(),arr.end());

	long i=0;
	long sum=0;
	long count=0;

	while(i != arr.size()){
		sum = sum + arr[i];

		if(sum > k)
			break;

		count++;
		i++;
	}

	cout << count << endl;
}