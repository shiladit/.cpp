/* https://www.geeksforgeeks.org/sort-an-array-according-to-absolute-difference-with-given-value/ */

#include <bits/stdc++.h>

using namespace std;

bool compare(const pair<long,long> &a, const pair<long,long> &b){
	return a.second < b.second;
}

int main() {
	long size,temp,diff;
	cin >> size;
	cin >> diff;


	vector <long> arr;
	vector <pair <long,long> > brr;

	while(size--){
		cin >> temp;
		arr.push_back(temp);
	}

	for(int i=0;i<arr.size();i++){
		int b = abs(arr[i]-diff);
		brr.push_back(make_pair(arr[i],b));
	}

	sort(brr.begin(),brr.end(),compare);

	vector <pair <long,long> > :: iterator it;
	
	for(it = brr.begin();it != brr.end() ; it++)
		cout << it->first << " ";

	cout << endl;

}