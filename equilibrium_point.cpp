#include <bits/stdc++.h>

using namespace std;

int main() {
	int size,temp;
	cin >> size;


	vector <int> arr;
	int sum=0;

	for(int i=0;i<size;i++){
		cin >> temp;
		arr.push_back(temp);
		sum =sum + temp;
	}

	int left_sum =0;
	int right_sum =sum;

	bool flag = false;

	for(int i=0;i<size;i++){

		cout << i << endl;
		if(i-1>=0)
			left_sum = left_sum + arr[i-1];
		if(i+1<size)
			right_sum = right_sum - arr[i] ;

		cout << left_sum << " -- " << right_sum << endl;

		if(left_sum == right_sum){
			flag = true;
			cout << "The index: " << i << endl;
		}
		
		//1 3 5 2 2

	}

	if(!flag)
			cout << "-1\n" ;


}