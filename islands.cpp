#include <bits/stdc++.h>
using namespace std;
#define MAX 1000  

vector <vector <bool> >  visited(MAX,vector <bool> (MAX));

int findIslands(int A[MAX][MAX],int N,int M);
int main() {
	// your code goes here
	int T;
	cin>>T;
	int A[MAX][MAX];
	while(T--)
	{
		int N,M;
		cin>>N>>M;
		memset(A,0,sizeof A);
		for(int i=0;i<N;i++)
		for(int j=0;j<M;j++)
		cin>>A[i][j];
		cout<<findIslands(A,N,M)<<endl;
	}
	return 0;
}

bool isSafe(int a,int b,int N,int M){
    if(a>=0 && a <N && b>=0 && b <M)
        return true;
    else
        return false;
}

void bfs(int i,int j,int A[MAX][MAX],int N,int M){
    int a_x[8] = {1,0,-1,0,1,-1,1,1};
    int a_y[8] = {0,1,0,-1,1,-1,-1,-1};
    
    queue <pair <int,int> > q;
    q.push(make_pair(i,j));
    visited[i][j] = true;
    
    while(!q.empty()){
        pair <int,int> p = q.front();
        q.pop();

        // visited[p.first][p.second] = true;

        // cout << p.first << " -- " << p.second << endl;
        
        for(int k=0;k<8;k++)
            if(A[p.first+a_x[k]][p.second+a_y[k]] == 1 && isSafe(p.first+a_x[k],p.second+a_y[k],N,M) && visited[p.first+a_x[k]][p.second+a_y[k]] == false){
                q.push(make_pair(p.first+a_x[k],p.second+a_y[k]));
                visited[p.first+a_x[k]][p.second+a_y[k]] = true;
            }
    }
}

int findIslands(int A[MAX][MAX], int N, int M)
{

// bool** visited =(bool**)malloc(sizeof(bool)*N);

// for(int i=0;i<N;i++)
//     visited[i] = (bool*)malloc(sizeof(bool)*M);



// for(int i=0;i<N;i++)
//     for(int j=0;j<M;j++)
//         visited[i][j] = false;

int count = 0;

for(int i=0;i<N;i++)
    for(int j=0;j<M;j++)
        if(A[i][j] == 1 && visited[i][j] == false){
             bfs(i,j,A,N,M);
             count++;
        }
  
return count;
}