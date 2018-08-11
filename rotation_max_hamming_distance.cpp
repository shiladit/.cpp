#include <bits/stdc++.h>

using namespace std;


void print_vector(vector <int> a){
	for(int i=0;i<a.size();i++)
		cout << a[i] << " ";

	cout << endl;
}

int calculate_max_hamming(vector <int> arr,vector <int> brr){
	int k=0;
	int count=0;
	int max_val = -INT_MAX;

	for(int i=0;i<brr.size();i++){
		for(int j=i,k=0;j<i+arr.size() && j != brr.size();j++,k++){
			if(arr[k]!= brr[j])
				count++;
		}
		
		if(count>max_val)
			max_val = count;

		count =0;
	}


	return max_val;
}


int main() {
	int num;
	cin >> num ;

	vector <int> arr;
	vector <int> :: iterator it;

	while(num != 0) {
		it = arr.begin();
		int rem = num%10;
		arr.insert(it,rem);
		num = num/10;
	}

	// print_vector(arr);

	vector <int> brr;

	for(int x=0;x<2;x++){
		for(int i=0;i<arr.size();i++)
			brr.push_back(arr[i]);
	}

	// print_vector(brr);

	cout << calculate_max_hamming(arr,brr) << endl;
}