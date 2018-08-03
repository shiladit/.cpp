#include<bits/stdc++.h>

using namespace std;

int main() {

	map <int,int> umap;

	int n,m,temp;
	int sum=0;

	cin >> n;
	for(int i=0;i<n;i++){
		cin >> temp;
		if(umap.find(temp) == umap.end())
			umap[temp] =1;
		else
			++umap[temp];	
	}

	cin >> m;
	for(int i=0;i<m;i++){
		cin >> temp;
		if(umap.find(temp) == umap.end())
			umap[temp] =1;
		else
			++umap[temp];	
	}

	map <int,int> :: iterator it;

	for(it = umap.begin();it != umap.end();it++){
		if(it->second == 1)
			sum = sum + it->first;
	}

	cout << sum << endl;
}