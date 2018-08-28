/* https://www.geeksforgeeks.org/segregate-even-odd-numbers-set-3/ */

#include<bits/stdc++.h>

using namespace std;

int main() {
	int size,temp;
	cin >> size;

	vector <int> arr;

	while(size--){
		cin >> temp;
		arr.push_back(temp);
	}

	int i=0;
	int j=arr.size()-1;

	while(i<j){
		if(arr[i]%2 ==1 && arr[j]%2==1) //Both are odd
			j--;
		else if(arr[i]%2 ==1 && arr[j]%2 ==0) // End is even
		{
			int temp = arr[j];
			arr[j] = arr[i];
			arr[i] = temp;

			i++;
			j--;
		}
		else if(arr[i]%2 ==0 && arr[j]%2 ==0)
			i++;
		else{
			i++;
			j--;
		}

	}

	for(int i=0;i<arr.size();i++)
		cout << arr[i] << " ";

	cout << endl;
}