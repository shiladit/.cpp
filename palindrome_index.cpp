#include <bits/stdc++.h>
using namespace std;

bool check_pali(string s,int l,int r){

	int i= l;
	int j = r;

	while(i<j){
		if(s[i] != s[j])
			return false;
		i++;
		j--;
	}

	return true;
}

int main() {
	int n;
	cin >> n;

	for(int i=0;i<n;i++){
		string s;
		cin >> s;
		int l= 0;
		int r= s.length()-1;

		if(check_pali(s,l,r))
			cout << "-1\n";
		else
		{
			
			while(l < r){
				if(s[l] != s[r]){
					if(check_pali(s,l+1,r)){
						cout << l << endl;
						break;
					}

					if(check_pali(s,l,r-1)){
						cout << r << endl;
						break;
					}

					cout << "-1\n";
				}
				l++;
				r--;
			}

		}
	}
}