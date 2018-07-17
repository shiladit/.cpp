#include<bits/stdc++.h>

using namespace std;

map <int,int> umap;

void find_majority(int arr[],int size) {

	for(int i=0;i<size;i++) {
		if(umap.find(arr[i]) == umap.end())
			umap.insert(make_pair(arr[i],1)); //first time insertion
		else
			umap[arr[i]]++;
	}
	int flag=0;
	map <int,int>:: iterator it;
	for(it = umap.begin();it !=umap.end();it++){
		if(it->second > size/2){
			cout << it->first << endl;
			flag =1;
			break;
		}
	}

	if(!flag)
		cout << "No Majority Element exists\n";
	
}

int main(){
	int T;
	cin >> T;
	while(T) {
		int size;
		cin >> size;
		int arr[size];
		for(int i=0;i<size;i++){
			int x;
			cin >> x;
			arr[i] = x;
		}
		find_majority(arr,size);

		T--;
	}
}