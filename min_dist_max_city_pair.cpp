/* There are n cities in a circle and distance between every adjacent pair of cities was given.
 We were asked to determine a pair of cities such that the minimum distance to travel between them is maximum.*/

#include <bits/stdc++.h>
using namespace std;

#define INF 99999

/* 99999 is the weight assigned to infinity, otherwise it will overfow int if you use INT_MAX */

int main() {

	int arr[4][4] = {{0,3,INF,7},
					{8,0,2,INF},
					{5,INF,0,1},
					{2,INF,INF,0}};

	int result[4][4];

	//Initialize
	for(int i=0;i<4;i++)
		for(int j=0;j<4;j++)
			result[i][j] = arr[i][j];

	for(int k=0;k<4;k++) 
		for(int i=0;i<4;i++)
			for(int j=0;j<4;j++)
				if(i != j)
					result[i][j] = min(result[i][j], result[i][k] + result[k][j]);

	//PRINT
	cout << "--------------------------------\n";		
	cout << "Printing All Pair Shortest Paths\n";
	cout << "--------------------------------\n";		
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++)
			 cout << result[i][j] << " ";
		cout << endl;	
	}
	cout << "------------------------------------------------------------------------------\n";		
	cout << "Printing city which has the maximum value of the minimum distance between them\n";

	int city1;
	int city2;
	int max_val = -INF;

	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++)
			 if(i!=j && result[i][j] != INF && result[i][j] > max_val){
			 	max_val = result[i][j];
			 	city1 = i;
			 	city2 = j;
			 }
	}

	cout << "city1 : " << city1 << " city2 : " << city2 << " Distance is: " << max_val << endl;


}