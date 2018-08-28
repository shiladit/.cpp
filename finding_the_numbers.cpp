/* Finding the numbers */

#include <bits/stdc++.h>

using namespace std;

int main(){
	 long t;
	 cin >> t;

	 while(t--){
	 	long n,temp;
	 	cin >> n;

	 	vector <long> arr;
	 	map <long,long> umap;

	 	for(int i=0;i<(2*n+2);i++){
	 		cin >> temp;
	 		if(umap.find(temp) == umap.end())
	 			umap[temp] = 1;
	 		else
	 			umap[temp]++;

	 	}

	 	map <long,long> :: iterator it;

	 	for(it=umap.begin();it != umap.end();it++){
	 		if((it->second)%2 != 0)
	 			arr.push_back(it->first);	
	 	}

	 	sort(arr.begin(),arr.end());

	 	for(int i=0;i<arr.size();i++){
	 		cout << arr[i] << " ";
	 	}

	 	cout << endl;

	 }
}