#include<bits/stdc++.h>

using namespace std;


int main() {
	
	int T;

	cin >> T;

	while(T){
	
	int N;
	cin >> N;
	int sum = 0;
	int count =0;

	for(int i=1;i<INT_MAX;i++){
		sum = sum+i;
		count++;
		if(sum > N)
			break;
	}
	cout << count-1 << endl;


	T--;
	}
}