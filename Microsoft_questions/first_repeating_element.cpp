#include<bits/stdc++.h>
#include<algorithm>

using namespace std;

void first_rep_ele(vector <int> arr,int size){
	map <int,int> umap;
	vector <int> index;
	int u=0;

	for(u=0;u<size;u++){
		if(umap.find(arr[u]) == umap.end()){
			umap.insert(make_pair(arr[u],u+1));
			// cout << arr[u] << "-> "<< u+1<< endl;
		}
		else
		{
			index.push_back(umap[arr[u]]);
			
		}
	}
	
	vector <int> :: iterator it;
	it = index.begin();
	int min = INT_MAX;
	// while(it != index.end()){
	// 	cout << *it << " ";
	// 	it++;
	// }
	int ind_size = index.size();
	for(int x=0;x<ind_size;x++){
		if(index[x] < INT_MAX )
			min = index[x];
	}

	if(min != INT_MAX)
		cout << min << endl;
	else
		cout << "No repeating elements\n";
}

int main(){
	int T;
	cin >> T;
	while(T) {
		int size,val;
		cin >> size;
		vector <int> arr;
		for(int i=0;i<size;i++){
			cin >> val;
			arr.push_back(val);
		}

		first_rep_ele(arr,size);

		T--;
	}
}