#include <bits/stdc++.h>

using namespace std;

vector <int> convert_to_binary (int x){
	vector <int> result;

	while(x!=0){
		int a = x%2;
		result.push_back(a);
		x = x >> 1;
	}

	return result;
}

void print_v(vector <int> arr){
	for(int i=0;i<arr.size();i++)
		cout << arr[i] << " ";

	cout << endl;
}

int main() {

	int a ,b;
	cin >> a >> b;

	vector <int> arr1;
	vector <int> arr2;

	arr1 = convert_to_binary(a);
	arr2 = convert_to_binary(b);

	// print_v(arr1);
	// print_v(arr2);

	vector <vector <int> > result(arr1.size()+1,vector<int>(arr2.size()+1));

	for(int i=1;i<arr1.size()+1;i++)
		for(int j=1;j<arr2.size()+1;j++)
			if(arr1[i-1] == arr2[j-1])
				result[i][j] = 1 + result[i-1][j-1];
			else
				result[i][j] = max(result[i-1][j],result[i][j-1]);

	cout << result[arr1.size()][arr2.size()] << endl;		
}