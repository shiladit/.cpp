#include<bits/stdc++.h>

using namespace std;

int main(){
	
	int t;
	cin >> t;

	while(t--){
		int n,a,b;
		cin >> n >> a >> b;

		map <int,int> map1;

		for(int i=0;i<n;i++)
			map1[((i*a)+(n-1-i)*b)] = 1;
		
		map <int,int> :: iterator it;

		for(it=map1.begin();it!= map1.end(); it++)
			cout << it->first << " ";

		cout << endl;
	}
}