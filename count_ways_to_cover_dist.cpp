#include <bits/stdc++.h>
using namespace std;


int count_ways(int n,int* arr){
	
	int count = 0;

	if(n < 0)
		return 0;
	if(n == 0)
		return 1;

	for(int i=0;i<3;i++)
		count += count_ways(n-arr[i],arr);

	return count;
}

int main() {
	int n = 4;
	int arr[3] = {1,2,3};

	int count = 0;

	for(int i=0;i<3;i++)
		count += count_ways(n-arr[i],arr);

	cout << count << endl;
}