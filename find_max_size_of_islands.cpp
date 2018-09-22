#include <bits/stdc++.h>

using namespace std;

bool visited[5][5] = {{false}};

bool isSafe(int x ,int y){

	if((x >=0 && x<=4) && (y >=0 && y<=4))
		return true;
	else
		return false;
}

int call_dfs(int mat[5][5],int x,int y){
	int rowx[] = {0,0,1,-1,1,-1,1,-1};
	int rowy[] = {1,-1,0,0,1,1,-1,-1};

	queue <pair <int,int> > q;

	q.push(make_pair(x,y));

	int count=0;

	while(!q.empty()){
		pair <int,int> p = q.front();
		q.pop();

		for(int i=0;i<8;i++){
			if(isSafe(p.first+rowx[i],p.second+rowy[i]) && mat[p.first+rowx[i]][p.second+rowy[i]] == 1 && visited[p.first+rowx[i]][p.second+rowy[i]] == false){
				visited[p.first+rowx[i]][p.second+rowy[i]] = true;
				q.push(make_pair(p.first+rowx[i],p.second+rowy[i]));
				count++;
			}
		}

	}  

	return count;
}



int maxIslands(int mat[5][5]){

int max_count = -INT_MAX;

	for(int i=0;i<5;i++){
		for(int j=0;j<5;j++){
			if(mat[i][j] == 1 && visited[i][j] == false){
				int val = call_dfs(mat,i,j);
				// cout << val << " ";
				if(val > max_count)
					max_count = val;
			}
		}
	}

	return max_count;
}


int main()
{
    int M[5][5]= {  {1, 1, 0, 0, 0},
			        {0, 1, 0, 0, 1},
			        {1, 0, 0, 1, 1},
			        {0, 0, 0, 0, 0},
			        {1, 0, 1, 0, 1}
    };
 
    printf("Max size of island: %d\n", maxIslands(M));
 
    return 0;
}