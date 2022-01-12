#include <iostream>
#include <vector>
using namespace std;

int calc_missing_positive(vector <int> &arr)
{
	for(int i=0;i<arr.size();i++)
	{
		while(arr[i]>0 and arr[i] <= arr.size() and arr[i] != arr[arr[i]-1])
		{
			swap(arr[i],arr[arr[i]-1]);
		}
	}

	for(int i=0;i<arr.size();i++)
	{
		if(arr[i] != (i+1))
			return (i+1);
	}

	return arr.size()+1;
}

int main()
{
	int n;
	cin >> n;
	vector <int> arr(n);

	for(int i=0;i<n;i++)
	{
		cin >> arr[i];
	}

	cout << calc_missing_positive(arr) << endl;

	return 0;
}