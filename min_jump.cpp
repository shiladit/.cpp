#include <bits/stdc++.h>

using namespace std;

int main() {
	int arr[10] = {2,3,1,1,2,4,2,0,1,1};

	vector <int> result(10,INT_MAX);
	vector <int> actual_jump(10,-1);

	result[0] = 0; // Starting point 

	for(int i=1;i<10;i++)
		for(int j=0;j<i;j++) {
			if((i-j) <= arr[j]){
				result[i] = min((result[j]+1),result[i]);
			}

		}

	for(int i=0;i<result.size();i++)
		cout << result[i] << " ";

	cout << endl;

}