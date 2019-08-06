#include<bits/stdc++.h>
using namespace std;

int main() {
	
	int size;
	cin >> size;

	vector <vector <int> > arr(size,vector <int> (size));

	for(int i=0;i<size;i++)
		for(int j=0;j<size;j++){
			cin >> arr[i][j];
		}

	// Implementing n! naive solution

	vector <int> tour;

	for(int i=0;i<size;i++){
		tour.push_back(i);
	}

	tour.push_back(0);

	int min_dist = INT_MAX;

	do {
		int dis = 0;

		for(int i=1;i<tour.size();i++){
			if(arr[tour[i-1]][tour[i]] != 0){
			dis +=arr[tour[i-1]][tour[i]]; 
			// cout << dis << " ";
			}
			else{
				dis = 1000;
			}
			
		}

		if(dis < min_dist){
			min_dist = dis;

		}

	}while(next_permutation(tour.begin()+1,tour.end()-1));

	cout << "The mincost tour is: " << min_dist << endl;

}