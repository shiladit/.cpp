#include <bits/stdc++.h>

using namespace std;

bool compare(const pair <long,long>  &a,const pair <long,long>  &b){
	return (a.second > b.second);
}

int main() {
	long size,temp;
	cin >> size;


	map <long,long> umap;

	for(int i=0;i<size;i++){
		cin >> temp;

		if(umap.find(temp) == umap.end()){
			umap[temp] =1;
			// cout << "Hi\n";
		}
		else {
			umap[temp]++;
			// cout << "NOT\n";
		}
	}

	map <long,long> :: iterator it;
	vector <pair <long,long> > arr;

	for(it = umap.begin();it != umap.end() ; it++){
		arr.push_back(make_pair(it->first,it->second));
	}

	sort(arr.begin(),arr.end(),compare);

	vector <pair <long,long > > :: iterator xx;
	for(xx = arr.begin();xx != arr.end() ; xx++){
		cout << xx->first << " -- " << xx->second << endl;
	}

	

}