/* https://www.geeksforgeeks.org/nearly-sorted-algorithm/ */

#include <bits/stdc++.h>

using namespace std;

int main() {
	long size,temp,k;
	cin >> size;
	cin >> k;

	vector <long> arr;
	while(size--){
		cin >> temp;
		arr.push_back(temp);
	}

	priority_queue <long , vector<long> , greater<long> > pq; //MIN HEAP

	for(int i=0;i<k;i++){
		pq.push(arr[i]);
	}

	int j=k;

	while(!pq.empty()){
		cout << pq.top() << " ";
		pq.pop();

		if(j<arr.size()){
			pq.push(arr[j]);
			j++;
		}

	}

	cout << endl;


}