// Leetcode
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> dist(200 , vector<int> (200, 0));

// UP, DOWN, LEFT, RIGHT
int arr_x[4] = {-1,1,0,0}; 
int arr_y[4] = {0,0,-1,1};

bool isSafe(int x,int y,int m,int n)
{
	if(x >=0 and x<m and y>=0 and y<n)
		return true;
	else
		return false;
}

int dfs(int x,int y,int val,vector < vector <int> > &matrix,int m,int n)
{
	if(isSafe(x,y,m,n) == false)
	{
			return 0;
	}

	if(matrix[x][y] > val)
	{
		
		if(dist[x][y] != 0)
		{
				return dist[x][y];
		}
		
		int up = 1 + dfs(x + arr_x[0], y + arr_y[0], matrix[x][y], matrix, m, n);
		int down = 1 + dfs(x + arr_x[1], y + arr_y[1], matrix[x][y], matrix, m, n);
		int left = 1 + dfs(x + arr_x[2], y + arr_y[2], matrix[x][y], matrix, m, n);
		int right = 1 + dfs(x + arr_x[3], y + arr_y[3], matrix[x][y], matrix, m, n);

		dist[x][y] = max(up,max(down,max(left,right)));
		return dist[x][y];
	}

	return 0;	
}

int main()
{
	int m,n;
	cin >> m >> n;
	vector < vector <int> > matrix(m, vector <int> (n));

	/* Input */
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin >> matrix[i][j];
		}
	}

	int max_count = 1;

	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			max_count = max(dfs(i,j,-99999,matrix,m,n),max_count);
		}
	}

	/* DEBUG
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout << dist[i][j] << " ";
		}
		cout << endl;
	}
	*/
	
	cout << max_count << endl;
	return 0;
}
