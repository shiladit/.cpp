#include<bits/stdc++.h>

using namespace std;

int main() {
	vector <int> arr;
	int temp,size;

	cin >> size;

	for(int i=0;i<size;i++){
		cin >> temp;
		arr.push_back(temp);
	}

	int incl = arr[0] ;
	int excl = 0;

	for(int i=1;i<arr.size()-1;i++){
		int old_incl = incl;
		incl = max((excl + arr[i]),incl);
		excl = old_incl ;

	}

	int new_max = max(incl,excl) ;

	//Choosing last element and rejecting last element

	cout <<  max((new_max+arr[arr.size()-1]-arr[arr.size()-2]-arr[0]),new_max) << endl;
}