#include <bits/stdc++.h>

using namespace std;

#define R 3
#define C 3

int min (int a ,int b,int c){
	return min(a,min(b,c));
}

int minCost(int cost[R][C]){
	int aux[R+1][C+1];

	for(int i=0;i<R+1;i++)
		for(int j=0;j<C+1;j++){
			if(i==0 || j==0)
				aux[i][j] = cost[0][0];
		}

	for(int i=1;i<R+1;i++)
		for(int j=1;j<C+1;j++)
			aux[i][j] = cost[i-1][j-1];

	// for(int i=0;i<R+1;i++){
	// 	for(int j=0;j<C+1;j++){
	// 		cout << aux[i][j] << " ";
	// 	}	
	// 	cout << endl;
	// }

	for(int i=1;i<R+1;i++)
		for(int j=1;j<C+1;j++){
			aux[i][j] = aux[i][j] + min(aux[i-1][j],aux[i][j-1],aux[i-1][j-1]);
		}


	for(int i=0;i<R+1;i++){
		for(int j=0;j<C+1;j++){
			cout << aux[i][j] << " ";
		}	
		cout << endl;
	}


	return aux[R][C];
}


int main() 
{ 
   int cost[R][C] = { {1, 2, 3}, 
                      {4, 8, 2}, 
                      {1, 5, 3} }; 
   printf("%d\n", minCost(cost)); 
   return 0; 
} 