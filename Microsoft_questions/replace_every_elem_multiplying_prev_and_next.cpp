/* https://www.geeksforgeeks.org/replace-every-array-element-by-multiplication-of-previous-and-next/ */

#include<bits/stdc++.h>

using namespace std;

void print_vector(vector <int> arr){
	for(int i=0;i<arr.size();i++)
		cout << arr[i] << " ";

	cout << endl;
}

int main(){
	int size,temp;
	cin >> size;


	vector <int> arr;

	while(size--){
		cin >> temp;
		arr.push_back(temp);
	}

	int prev;

	for(int i=0;i<arr.size();i++){
		if(i==0){
			prev= arr[i];
			arr[i]=arr[i]*arr[i+1];	
		}
		
		else if(i==arr.size()-1)
			arr[i]=prev*arr[i];

		else {	
			int temp_val = prev*arr[i+1];
			prev= arr[i];
			arr[i] = temp_val;
			
		}
	}

	print_vector(arr);
}