#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

void print_matrix(vector < vector <int> > matrix)
{
	for(int i=0;i<matrix.size();i++)
	{
		for(int j=0;j<matrix[i].size();j++)
		{
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}

	return;
}

void rotate(vector < vector <int> > &arr)
{
	int n = arr.size();
	/* Matrix is square */

	pair <int,int> lt;
	pair <int,int> rt;
	pair <int,int> lb;
	pair <int,int> rb;

	for(int i=0;i<(n-(i+1));i++)
	{
		lt.first = i; lt.second = i;
		rt.first = i; rt.second = n-(i+1);
		lb.first = n-(i+1); lb.second = i;
		rb.first = n-(i+1); rb.second = n-(i+1);

		for(int j=i;j<(n-(i+1));j++)
		{
			int a = arr[lt.first][lt.second];
			int b = arr[rb.first][rb.second];

			arr[rb.first][rb.second] = arr[rt.first][rt.second];
			arr[lt.first][lt.second] = arr[lb.first][lb.second];
			arr[rt.first][rt.second] = a;
			arr[lb.first][lb.second] = b;

			lt.second++;
			rt.first++;
			lb.first--;
			rb.second--;
		} 
	}

	return;
}

int main()
{
	int n;
	cin >> n;
	assert(n <= 20);

	vector < vector <int> > arr(n, vector <int> (n));

	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin >> arr[i][j];
		}
	}

	rotate(arr);
	print_matrix(arr);

	return 0;
}
