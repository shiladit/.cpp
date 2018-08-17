/* https://www.geeksforgeeks.org/minimum-length-unsorted-subarray-sorting-which-makes-the-complete-array-sorted/ */

#include <bits/stdc++.h>

using namespace std;

int check_index(vector <int> arr,bool turn){
	int i;

	if(!turn){
		i=0;
		while(i != arr.size()){
			if(arr[i]>arr[i+1])
				break;
			i++;
		}
		return i;
	}
	else if (turn){
		i=arr.size()-1;
		while(i != -1){
			if(arr[i]<arr[i-1])
				break;
			i--;
		}
		return i;	
	}
	else
		;
	return -100;

}

void print_vector(vector <int> arr){
	for(int i=0;i<arr.size();i++){
		cout << arr[i] << " ";
	}

	cout << endl;
}

bool check_vector(vector <int> arr){
	for(int i=0;i<arr.size()-1;i++){
		if(arr[i]>arr[i+1])
			return false;
	}

	return true;
}

int main() {
	int size,temp;

	vector <int> arr;

	cin >> size;
	while(size--) {
		cin >> temp;
		arr.push_back(temp);
	}
	bool turn = false;
	int i = check_index(arr,turn);
	turn = !turn;
	int j = check_index(arr,turn);

	while(i != -1 || j != arr.size()){


		sort(arr.begin()+i,arr.begin()+j);

		bool flag = check_vector(arr);
		// cout << flag << endl;
		
		if(flag == true)
			break;

		if(turn)
			i--;
		else
			j++;

		turn = !turn;
	}

	cout << i+1 << " -- " << j << endl;

	print_vector(arr);

}