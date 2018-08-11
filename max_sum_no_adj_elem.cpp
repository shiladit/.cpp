/* https://www.geeksforgeeks.org/maximum-sum-such-that-no-two-elements-are-adjacent/ */

#include<bits/stdc++.h>

using namespace std;

int main() {
	int size,temp;
	cin >> size;

	vector <int> arr;

	for(int i=0;i<size;i++){
		cin >> temp;
		arr.push_back(temp);
	}

	int excl = 0;
	int incl = arr[0];

	for(int i=1;i<arr.size();i++){
		int old_incl = incl;
		int old_excl = excl;
		incl = excl + arr[i];
		excl = max(old_excl,old_incl);
	}

	cout << max(incl,excl) << endl;

}