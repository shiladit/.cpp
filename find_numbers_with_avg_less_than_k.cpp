#include <bits/stdc++.h>

using namespace std;

int main() {
	long long n,q,temp;
	cin >> n >> q;

	vector <long long> arr(n);

	for(int i=0;i<n;i++){
		cin >> temp;
		arr[i] = temp;
	}

	sort(arr.begin(),arr.end());

	map <long long,long long> umap;

		long long sum=0;

		for(int i=0;i<arr.size();i++){
			sum = sum + arr[i];
			long long average = sum / (i+1);
			umap[average] = i+1;
		}
		

	while(q--){

		long long k;

		cin >> k;

		map <long long,long long> ::  iterator it;

		it = umap.lower_bound(k);
		if(it->first == 0)
			cout << arr.size() << endl;
		else{
			it--;
			cout << it->second << endl;
		}
		
	}

}