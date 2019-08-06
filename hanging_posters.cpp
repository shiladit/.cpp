#include <bits/stdc++.h>
#define lb long double

using namespace std;

int main() {
	lb n,h;
	cin >> n >> h;

	vector <lb> wallp;
	vector <lb> length;

	 lad = 0;

	for(lb i=0;i<n;i++){
		lb x;
		cin >> x;
		wallp.push_back(x);
	}

	for(lb i=0;i<n;i++){
		lb x;
		cin >> x;
		length.push_back(x);
	}

	/* Computing */

	for(lb i=0;i<n;i++){
		lb bolt = wallp[i] + .25*length[i];
		lb hold_point = bolt - .5*length[i];

		if((hold_point - h) > lad)
			lad = hold_point -h;
	}

	cout << (int)ceil(lad) << endl;
}