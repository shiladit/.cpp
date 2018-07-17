#include<bits/stdc++.h>

using namespace std; 

int main() {
	
	int size1,size2;
	cin >> size1;

	map <int,int> umap;

	int temp;

	for(int i=0;i<size1;i++){
		cin >> temp;
		if(umap.find(temp) == umap.end())
			umap.insert(make_pair(temp,1));
		else
			umap[temp]++;

	}

	map <int,int> :: iterator it;
	// for(it = umap.begin();it != umap.end() ;it++)
	// 	cout << it->first << " --> " << it->second << endl;

	cin >> size2;

	for(int i=0;i<size2;i++){
		cin >> temp;
		if(umap.find(temp) != umap.end())
			umap[temp]--;
	}

	vector <int> arr;
	
	for(it = umap.begin();it != umap.end() ;it++) {
	    if((it->second) < 0)
	    	arr.push_back(it->first);
	    	// cout << it->first  <<  "  " ;
	}


	sort(arr.begin(),arr.end());


	for(int i=0;i<arr.size();i++)
		cout << arr[i] << " ";

	
	cout << endl;


}