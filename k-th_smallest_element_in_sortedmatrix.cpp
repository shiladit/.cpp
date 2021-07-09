#include <iostream>
#include <vector>
#include <cassert>
#include <map>
using namespace std;

int find_k(vector < vector <int> > &arr,int k)
{
	int n = arr.size();
	map <int,int> umap;

	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
			umap[arr[i][j]]++;
	}

	map <int,int> :: iterator it;
	it = umap.begin();
	int count = 0;

	while(it != umap.end())
	{	
		count = count + it->second;
		if(count >= k)
			break;
		it++;
	}

	return it->first;
}

int main()
{
	int n;
	cin >> n;
	assert((n >= 1) and (n<= 300));

	vector < vector <int> > arr(n, vector <int> (n));
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin >> arr[i][j];
		}
	}

	int k;
	cin >> k;

	cout << find_k(arr,k) << endl;

	return 0;
}