#include <bits/stdc++.h>

using namespace std;


bool check_three(long num){
	int temp,count=0;

	while(num !=0 ){
		temp = num%10;
		if(temp == 3)
			count++;

		num = num/10;
	}

	if(count >=3)
		return true;
	else
		return false;
}

int main() {
	long long t,temp;
	cin >> t;

	while(t--){
		long long num;
		cin >> num;

		while(1){
			if(check_three(num) == true)
				break;

			num++;

		}

		cout << num << endl;
	}
}