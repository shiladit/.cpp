/* This Question came in APPLE 2018 IITMADRAS */

#include <bits/stdc++.h>
using namespace std;

bool compare(string a,string b){
	return a.length() < b.length();
}

void print_vector(vector <string> arr){

	for(int i=0;i<arr.size();i++)
		cout << arr[i] << " ";

	cout << endl;
}

int main() {
	vector <string> arr;

	int size;
	cin >> size;

	/* Sample Input 
	6
	a 
	b
	ba
	bc
	bca
	bcda
	*/
	map <string,int> umap;

	while(size--){
		string s;
		cin >> s;
		arr.push_back(s);
		umap[s] = 1;
	}

	sort(arr.begin(),arr.end(),compare);

	// print_vector(arr);

	for(int i=0;i<arr.size();i++){
		
		int len = arr[i].length();

		for(int j=0;j<len;j++){
			string t = arr[i];
			t.erase(j,1);
			if(umap[t]){
				umap[arr[i]] = max(umap[arr[i]],1+umap[t]);
			}
			
		}
	}

	map <string,int> :: iterator it;

	int max_val = -INT_MAX;
	string str;

	for(it = umap.begin();it != umap.end(); it++){
		// cout << it->first << " --> " << it->second << endl;
		if(it->second > max_val){
			str = it->first;
			max_val = it->second;
		}
	}

	cout << str << " " << max_val << endl;


}