#include <iostream>
#include <vector>

using namespace std;

bool canPartition_with_ksum(vector <int> &arr, vector <bool> visited, int sum, int target,int k)
{
	if(k == 0)
		return true;

	if(sum == target)
		return canPartition_with_ksum(arr, visited, sum, target, k-1);

	for(int i=0;i<arr.size();i++)
	{
		if(!visited[i])
		{
			visited[i] = true;
			return canPartition_with_ksum(arr, visited, sum + arr[i], target, k);
		}

		visited[i] = false;
	}

	return false;
}

bool canPartition(vector <int> &arr, int k)
{
	int sum = 0;

	for(int i=0;i<arr.size();i++)
	{
		sum = sum + arr[i];
	}

	if(k<=0)
		return false;

	if(sum%k != 0)
		return false;

	vector <bool> visited(arr.size(),false);

	return canPartition_with_ksum(arr,visited,0,sum/k,k);
} 

int main()
{
	int n,k;
	cin >> n;
	cin >> k;

	vector <int> arr(n);

	for(int i=0;i<n;i++)
	{
		cin >> arr[i];
	}

	if(canPartition(arr,k))
		cout << "true" << endl;
	else
		cout << "false" << endl;

	return 0;
}

/*

Test Case

7
4 3 2 3 5 2 1
4

*/