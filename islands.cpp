#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

#define MAX 1000

vector <vector <bool> > visited(MAX,vector <bool> (MAX));
int N,M;

bool isSafe(int a,int b,int N,int M){
	if(a>=0 && a <N && b>=0 && b <M)
		return true;

	return false;
}

void bfs(int i,int j,int A[MAX][MAX],int N,int M)
{
	int a_x[8] = {1,0,-1,0,1,-1,1,1};
	int a_y[8] = {0,1,0,-1,1,-1,-1,-1};
    
	queue <pair <int,int> > q;
	q.push(make_pair(i,j));
	visited[i][j] = true;

	while(!q.empty())
	{
		pair <int,int> p = q.front();
		q.pop();
		int off1 = p.first;
		int off2 = p.second;

		for(int k=0;k<8;k++)
		{
			if(isSafe(off1,off2,N,M)
			&& (A[off1][off2] == 1)
			&& (visited[off1][off2] == false))
			{
				q.push(make_pair(off1,off2));
				visited[off1][off2] = true;
			}
		}
	}
}

int findIslands(int A[MAX][MAX], int N, int M)
{
	int num_islands = 0;

	for(int i=0;i<N;i++)
	{
		for(int j=0;j<M;j++)
		{
			if(A[i][j] == 1 && visited[i][j] == false)
			{
				bfs(i,j,A,N,M);
				num_islands++;
			}
		}
	}
	return num_islands;
}

int main()
{
	int T,temp;
	cin >> T;
	int A[MAX][MAX];
	while(T--)
	{
		cin >> N >> M;

		memset(A,0,sizeof A);
		for(int i=0;i<N;i++)
			for(int j=0;j<M;j++)
			{
				cin >> temp;
				A[i][j] = temp;
			}

		findIslands(A,N,M);
	}
	return 0;
}
