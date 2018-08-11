#include<bits/stdc++.h>

using namespace std;

int main() {
	long n,temp;
	cin >> n;

	vector <long> arr;
	set <long> s;

	for(int i=0;i<n;i++){
		cin >> temp;
		arr.push_back(temp);
	}

	long i=0;
	long sum =0;
	long max_val = -INT_MAX;

	while(i != n){

		if(s.find(arr[i]) != s.end()){
			s.clear();
			if(sum > max_val)
				max_val = sum;

			s.insert(arr[i]);
			sum =0;
			sum = sum + arr[i];

		}
		else{
			s.insert(arr[i]);
			sum = sum + arr[i];
		}

		i++;
	}

	if(sum > max_val)
		max_val = sum;

	cout << max_val << endl;


}