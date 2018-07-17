#include<bits/stdc++.h>

using namespace std;

#define ci vector <int> ::iterator 

bool comp(const pair<int,int> &a, const pair<int,int> &b){
		return (a.second > b.second);
}

vector <int> compute_freq(vector <int> arr){
	map <int,int> umap;
	ci it;
	for(it =arr.begin(); it != arr.end(); it++){
		// cout << *it << endl;
		if(umap.find(*it) == umap.end())
			umap.insert(make_pair(*it,1));
		else
			umap[*it]++;
			
	}

	vector <pair<int,int>> mapcopy(umap.begin(),umap.end()); 
	sort(mapcopy.begin(),mapcopy.end(),comp);

	for(int i = 0;i<mapcopy.size();i++)
		cout << mapcopy[i].first << " " ;

	cout << endl;
	


	return arr;
}


int main(){
	int T;
	cin >> T;
	while(T) {
		int size,temp;
		cin >> size; // size of array
		vector <int> arr;
		for(int i=0;i<size;i++){
			cin >> temp;
			arr.push_back(temp);
		}
		arr = compute_freq(arr);
		T--;
	}
}