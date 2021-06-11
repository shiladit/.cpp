/* leetcode - O(1) solution */
#include <iostream>
#include <vector>
using namespace std;

/* such arbitrary values are chosen so that
we don't collide with values in the input matrix */
#define DEL_ROW -12209
#define DEL_COL -22209
#define DEL_ROWCOL -42209

void print_matrix(vector < vector <int> > &matrix, int n, int m)
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
}

void setZeroes(vector < vector <int> > &matrix) {
	int n = matrix.size();
	int m = matrix[0].size();

	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(matrix[i][j] == 0)
			{
				if(matrix[i][0] == DEL_COL || matrix[i][0] == DEL_ROWCOL)
					matrix[i][0] = DEL_ROWCOL;
				else
					matrix[i][0] = DEL_ROW;

				if(matrix[0][j] == DEL_ROW || matrix[0][j] == DEL_ROWCOL)
					matrix[0][j] = DEL_ROWCOL;
				else
					matrix[0][j] = DEL_COL;
			}
		}
	}

	/* Delete Marked Rows */
	for(int i=0;i<n;i++)
	{
		if(matrix[i][0] == DEL_ROW || matrix[i][0] == DEL_ROWCOL)
		{
			for(int j=1;j<m;j++)
				if(matrix[i][j] != DEL_ROW && matrix[i][j] != DEL_COL)
					matrix[i][j] = 0;
		}
	}

	/* Delete Marked Columns */
	for(int j=0;j<m;j++)
	{
		if(matrix[0][j] == DEL_COL || matrix[0][j] == DEL_ROWCOL)
		{
			for(int i=1;i<n;i++)
				if(matrix[i][j] != DEL_ROW && matrix[i][j] != DEL_COL)
					matrix[i][j] = 0;
		}
	}

	/* Replace markings with 0 */
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(matrix[i][j] == DEL_ROW || matrix[i][j] == DEL_COL || matrix[i][j] == DEL_ROWCOL)
			{
				matrix[i][j] = 0;
			}
		}
	}
	return;
}

int main()
{
	int n, m, temp;
	cin >> n >> m;
	vector < vector <int> > matrix(n, vector <int> (m));

	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cin >> temp;
			matrix[i][j] = temp;
		}
	}

	setZeroes(matrix);
	print_matrix(matrix,n,m);

	return 0;
}
