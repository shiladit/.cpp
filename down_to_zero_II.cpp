//shiladitya
#include <iostream>
#include <vector>
#include <math.h>
#include <climits>
#define ll long long
#define max 1000001
using namespace std;

int main() {
	ll q;
	cin >> q;

	vector <ll> arr;

	for(int i=0;i<q;i++){
		ll x;
		cin >> x;
		arr.push_back(x);
	}

	vector <ll> moves(max,-1);
	
	for(int i=0;i<4;i++){
		moves[i] = i;
	}

	for(int i=0;i<max;i++){
		if(moves[i] == -1 || moves[i] > 1+ moves[i-1])
			moves[i] = 1 + moves[i-1];
		for(int j=1;j<=i && j*i < max;++j){
			if(moves[j*i] == -1 || moves[j*i]>1+moves[i])
				moves[j*i] = 1+moves[i];
		}
	}

	for(int i=0;i<q;i++){
		cout << moves[arr[i]] << endl;
	}

}
