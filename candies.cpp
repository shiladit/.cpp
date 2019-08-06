#include <bits/stdc++.h>
using namespace std;

int main() {

	int n;
	cin >> n;

	vector <int> rating;

	for(int i=0;i<n;i++){
		int x;
		cin >> x;
		rating.push_back(x);
	}

	vector <int> candy(n,1);

	for(int i=1;i<n;i++){
		if(rating[i-1]>rating[i] && candy[i-1] == candy[i])
			candy[i-1]++;
		else if(rating[i] > rating[i-1] && candy[i-1] == candy[i])
			candy[i]++;
		else if(rating[i] > rating[i-1] && candy[i-1] > candy[i])
			candy[i] = candy[i-1] + 1;
		else if(rating[i] < rating [i-1] && candy[i] > candy[i-1])
			candy[i-1] = candy[i] + 1;
		else
			;
	}

	for(int i=n-1;i>=0;i--){
		if(rating[i-1]>rating[i] && candy[i-1] == candy[i])
			candy[i-1]++;
		else if(rating[i] > rating[i-1] && candy[i-1] == candy[i])
			candy[i]++;
		else if(rating[i] > rating[i-1] && candy[i-1] > candy[i])
			candy[i] = candy[i-1] + 1;
		else if(rating[i] < rating [i-1] && candy[i] > candy[i-1])
			candy[i-1] = candy[i] + 1;
		else
			;
	}

	// for(int i=0;i<n;i++)
	// 	cout << candy[i] << " ";

	// cout << endl;

	long long sum = 0;

	for(int i=0;i<n;i++){
		sum += candy[i];
	}

	cout << sum << endl;
}