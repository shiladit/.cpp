#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

bool binary_search(vector < vector <int> > &matrix, int target, int row, int left, int right)
{
	if(left > right)
		return false;

	int middle = left + ((right-left)/2);

	if(matrix[row][middle] == target)
		return true;
	else if(matrix[row][middle] < target)
		return binary_search(matrix,target,row,middle+1,right);
	else
		return binary_search(matrix,target,row,left,middle-1);
}

/* Doing binary search on every row */
bool searchMatrix(vector < vector <int> > &matrix, int target)
{
	int n = matrix.size();
	int m = matrix[0].size();

	for(int i=0;i<n;i++)
	{
		if(binary_search(matrix,target,i,0,m-1))
			return true;
	}
	return false;
}

int main()
{
	int n,m,temp;
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

	int target;
	cin >> target;

	if(searchMatrix(matrix,target))
		cout << "YES\n";
	else
		cout << "NO\n";

	return 0;
}
