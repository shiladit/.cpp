/* https://www.geeksforgeeks.org/given-an-array-of-numbers-arrange-the-numbers-to-form-the-biggest-number/ */

#include <bits/stdc++.h>

using namespace std;

bool compare(string X,string Y){
	string XY= X.append(Y);
	string YX= Y.append(X);

	if(XY >YX)
		return 1;
	else
		return 0;

}

int main() {
	int size;
	string temp;
	cin >> size;

	vector <string> arr;
	while(size--){
		cin >> temp;
		arr.push_back(temp);
	}

	sort(arr.begin(),arr.end(),compare);

	for(int i=0;i<arr.size();i++)
		cout << arr[i] << " ";

	cout << endl;

}