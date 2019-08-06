#include<bits/stdc++.h>

using namespace std;

int main() {

	int no_of_coins,temp;
	cin >> no_of_coins;


	vector <int> coins;

	for(int i=0;i<no_of_coins;i++){
		cin >> temp;
		coins.push_back(temp);
	}

	int N;
	cin >> N;

	vector <vector <int> > aux(coins.size()+1,vector <int> (N+1));


	for(int i=0;i<coins.size()+1;i++)
		for(int j=0;j<N+1;j++){
			if( j == 0)
				aux[i][j] = 1;
			else if (i==0)
				aux[i][j] = 0;
		}

	
	for(int i=1;i<coins.size()+1;i++)
		for(int j=1;j<N+1;j++){
			if(coins[i-1] <=j)
				aux[i][j] = aux[i-1][j] + aux[i][j-coins[i-1]];
			else
				aux[i][j] = aux[i-1][j];

		}

	for(int i=0;i<coins.size()+1;i++){
		for(int j=0;j<N+1;j++)
			cout << aux[i][j] << " ";
		cout << endl;
	}

}