#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin >> n;

	int num =1;

	while(num % n != 0 ){	

		num = num << 1;
		num = num | 1;
		
		// cout << num << " ";

		if(num == n){
		num = num << 1;
		num = num | 1;
			
		}

	}

	cout << num << endl;
}