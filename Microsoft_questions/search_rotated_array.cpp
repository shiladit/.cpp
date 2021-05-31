#include<bits/stdc++.h>

using namespace std;

bool found = false ;
int index_found =-1;

void print(vector <int> arr) {

	vector <int> :: iterator u;
	for(u=arr.begin();u !=arr.end(); u++)
		cout << *u << " ";

	cout << endl;
}

int find_seg(vector <int> arr,int size){
	
	int breaking_index = 0;

	for(int u=0;u<size;u++)
		if(arr[u]>arr[u+1]){
			breaking_index=u+1;
			break;
		}

	return breaking_index;
}

void binary_search(vector <int> arr,int lower,int upper,int x){

	if(upper >=lower){
		int mid = (lower+upper)/2;

	if(arr[mid] ==  x){
		// cout << "Found" << endl;
		found =true;
		index_found = mid;

		return;
	}
	if(x < arr[mid])
		return binary_search(arr,lower,mid-1,x);
	else 
		return binary_search(arr,mid+1,upper,x);
	}


}

int main() {
	int T,size;
	cin >> T;
	while(T) {
		int val,search_elem;
		cin >> size;
		vector <int> arr;
		for(int u=0;u<size;u++){
			cin >> val;
			arr.push_back(val);
		}
		cin >> search_elem;
		// print(arr);
		int seg = find_seg(arr,size);
		// cout << seg;
		binary_search(arr,0,seg-1,search_elem);
		binary_search(arr,seg,size-1,search_elem);

		if(!found )
			cout << "Not Found!\n"; 
		else
			cout << "Found! at index: " << index_found << endl ;

		T--;
	}
}