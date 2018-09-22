#include <bits/stdc++.h>

using namespace std;

int sol[4][4] = {{0}};

bool isSafe(int x,int y,int mat[4][4]){
	if(x >=0 && x<4 && y>=0 && y<4 && mat[x][y] == 1)
		return true;
	else 
		return false;
}

bool solve_Maze(int mat[4][4],int x,int y,int m,int n,int sol[4][4]){

 if(x == m-1 && y == n-1){
 	sol[x][y] =1;
 	return true;
 }

 if(isSafe(x,y,mat))
 	sol[x][y] = 1;
 else
 	return false;

 if (solve_Maze(mat,x+1,y,m,n,sol))
 	return true;
 if(solve_Maze(mat,x,y+1,m,n,sol))
 	return true;

 sol[x][y] = 0; //Backtracking step

 return false;

}



int main() {
	int mat[4][4] = { {1,1,1,0},{1,0,1,0},{0,0,1,0},{0,0,1,1}};

	 // Solution Matrix

	solve_Maze(mat,0,0,4,4,sol);

	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++)
			cout << sol[i][j] <<  " ";

		cout << endl;
		}
	
}