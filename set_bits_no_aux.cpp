#include<bits/stdc++.h>

using namespace std;

bool check_set(int x,int y){
	return (x & (1 << y)) ? true : false;
}

bool check_pali(int x){
	int i=0;
	int j = floor(log2(x));
	
	while(i < j){
		if( check_set(x,i) != check_set(x,j))
			return false;

		i++;
		j--;
	}

	return true;
}

int main() {
	int x;
	cin >> x;

	bool flag = check_pali(x);

	if(!flag)
		cout << "NO\n" << endl;
	else
		cout << "YES\n" << endl;
}