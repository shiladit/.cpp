#include <iostream>
#include <queue>
#include <vector>
using namespace std;

typedef pair<int, int> pi;
priority_queue<pi, vector<pi>, greater<pi> > pq;

vector <int> findClosestElements(vector <int> &arr,int k,int x)
{
	vector <int> result;	

	int n = arr.size();
	for(int i=0;i<n;i++)
	{
		int val = abs(arr[i] - x);
		pq.push(make_pair(val,arr[i]));
	}

	while(k)
	{
		result.push_back(pq.top().second);
		pq.pop();
		k--;
	}

	sort(result.begin(),result.end());	
	
	return result;
}

int main()
{
	vector <int> arr;
	int n,k,x,temp;

	cin >> n;

	for(int i=0;i<n;i++)
	{
		cin >> temp;
		arr.push_back(temp);
	}

	cin >> k >> x;
	
	vector <int> res = findClosestElements(arr,k,x);
	for(int i=0;i<res.size();i++)
		cout << res[i] << " ";
	cout << endl;

	return 0;
}
