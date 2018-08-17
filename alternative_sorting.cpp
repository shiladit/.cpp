/* https://www.geeksforgeeks.org/alternative-sorting/ */

#include <bits/stdc++.h>

using namespace std;

void alternative_sorting(vector <int> arr){
	sort(arr.begin(),arr.end());

	int i=0;int j= arr.size()-1;

	bool turn = false;

	while(i<=j){

		if(turn == false){
			cout << arr[j] << " " ;
			j--;
			turn = !turn; 
		}
		else{
			cout << arr[i] << " " ;
			i++;
			turn = !turn;
		}
	}
	cout << endl;
	
}


int main() {
	int size,temp;
	cin >> size;

	vector <int> arr;

	while(size--) {
		cin >> temp;
		arr.push_back(temp);
	}

	alternative_sorting(arr);

}