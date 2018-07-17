#include<bits/stdc++.h>
#include<algorithm>

using namespace std;
 


int main() {
	int T; //Test Cases
	int size,k;

	cin >> T;
	int val;

	while(T){
	cin >> size >> k;

int arr[size];

	for(int i=0;i<size;i++){
		cin >> val;
		arr[i] = val;
	}

	make_heap(arr,arr+size);

	while(k){
		 
		k--;
		size--;
		cout << arr[0] << endl;
		pop_heap(arr,arr+size);
	}
// 	for(int i=0;i<size;i++){
// 		cout << arr[i] << " ";
// }

	T--;

	}


}