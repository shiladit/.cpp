//Amazon

#include <vector>
#include <iostream>

using namespace std;

int arr_x[2] = {0,-1};
int arr_y[2] = {-1,0};

bool isSafe(int x,int y,int n,int m)
{
	if(x>=0 && x<n && y>=0 && y<m)
		return true;
	else
		return false;
}

int calculate_paths(vector < vector <int> > &matrix, vector < vector <int> > &result)
{
	int n = matrix.size();
	int m = matrix[0].size();

	for(int i=1;i<n;i++)
	{
		for(int j=1;j<m;j++)
		{
			// not an obstacle
			if(matrix[i][j] != 100)
			{
				int paths = 0;

				for(int v=0;v<2;v++)
				{
					int x = i+arr_x[v];
					int y = j+arr_y[v];

					if(isSafe(x,y,n,m) && matrix[x][y] == 0)
					{
						// adding number of different paths to reach here
						paths += result[x][y];
					}
				}

				result[i][j] = paths;
			}
		}
	}

	return result[n-1][m-1];
}

int main()
{
	/* 0 denotes free space
	100 denotes obstacle

	0   0   0   0   100
	0   100 100 0   0
	0   0   100 100 0
	100 0   100 100 0
	100 0   0   0   0

	Number of distinct paths = 2

	*/

	int n,m;
	cin >> n >> m;

	vector < vector <int> > matrix(n, vector <int> (m));

	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cin >> matrix[i][j];
		}
	}

	vector < vector <int> > result(n, vector <int> (m));

	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(((i == 0) || (j == 0)) && matrix[i][j] == 0)
				result[i][j] = 1;
			else
				result[i][j] = 0;

			//DEBUG
			//cout << result[i][j] << " ";
		}
		//cout << endl;
	}

	cout << calculate_paths(matrix,result) << endl;

	return 0;
}

/*

5 5
0   0   0   0   100
0   100 100 0   0
0   0   100 100 0
100 0   100 100 0
100 0   0   0   0

*/