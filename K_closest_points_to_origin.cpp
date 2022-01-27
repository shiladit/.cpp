#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int compute_distance(int x,int y)
{
	return (x*x) + (y*y);
}

void find_k_closest(vector < vector <int> > &arr,int k)
{
	priority_queue <pair <int,int>, vector<pair <int,int> >, greater<pair <int,int> > > pq;

	for(int i=0;i<arr.size();i++)
	{
		int dist = compute_distance(arr[i][0],arr[i][1]);
		pq.push(make_pair(dist,i));
	}

	for(int i=0;i<k;i++)
	{
		pair <int,int> elem = pq.top();
		cout << arr[elem.second][0] << " , " << arr[elem.second][1] << endl;
		pq.pop();
	}

	return;
}

int main()
{
	int n,k;
	cin >> n >> k;

	vector < vector <int> > arr;

	for(int i=0;i<n;i++)
	{
		int x,y;
		cin >> x >> y;
		vector <int> temp(2);
		temp[0] = x;
		temp[1] = y;
		arr.push_back(temp);
	}

	find_k_closest(arr,k);

	return 0;
}