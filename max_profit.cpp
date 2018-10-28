#include <bits/stdc++.h>
using namespace std;

int main() {
	int no_of_cities;

	int arr[6] = {1,2,3,4,9,8};

	vector <int> result(6);

	for(int i=0;i<6;i++){
		result[i] = arr[i];
	}

	int j=1;int i=0;

	while(j!=result.size()){
		for(i=0;i<j;i++){
			if((arr[j]%arr[i]) == 0)
				result[j] = max(result[i]+arr[j],result[j]);
		}
		j++;
	}

	//Output resultant vector

	// for(int i=0;i<result.size();i++)
	// 	cout << result[i] << " ";
	// cout << endl;

	cout << result[result.size()-1] << endl;
}