#include <bits/stdc++.h>

using namespace std;

int main() {

	int n,a;
	cin >> n;
	map <int,int> umap;

	map <int,int> :: iterator it;

	for(int i=0;i<n;i++){
		cin >> a;
		if(umap.find(a) == umap.end())
			umap[a]= 1;
		else
			umap[a]++;
	}


	if(umap.size() == 1)
		cout << "0" << endl;
	else if (umap.size() == 2){
		it = umap.begin();
		cout << min(it++->second,it->second) << endl;
	}
	else{
		int sum = 0;
		int max_val =0;
		for(it=umap.begin();it!=umap.end();it++){
			sum = sum + it->second;
			if(it->second > max_val)
				max_val = it->second;
		}

		cout << sum-max_val << endl;
	}

}