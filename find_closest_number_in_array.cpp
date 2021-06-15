#include <iostream>
#include <vector>
using namespace std;

int closest(int x,int y, int t)
{
	if(abs(t-y) > abs(t-x))
		return x;
	else
		return y;
}

int find_closest(vector <int> &arr, int target)
{
	int i=0;
	int j=arr.size()-1;

	if(target <= arr[0])
		return arr[0];
	
	if(target >= arr[arr.size()-1])
		return arr[arr.size()-1];

	int middle = 0;

	while(i<j)
	{
	
		middle = i + (j-i)/2;
		
		if(arr[middle] == target)
			return arr[middle];
		
		else if (arr[middle] > target)
		{
			if(middle > 0 && target > arr[middle-1])
				return closest(arr[middle],arr[middle-1],target);

			j = middle;
		}
	
		else
		{
			if(middle < arr.size()-1 && target < arr[middle+1])
				return closest(arr[middle],arr[middle+1],target);

			i = middle+1;
		}

	}
	
	return arr[middle];
}

int main()
{
	int n,temp;
	cin >> n;
	vector <int> arr;

	for(int i=0;i<n;i++)
	{
		cin >> temp;
		arr.push_back(temp);
	}

	sort(arr.begin(),arr.end());

	int target;
	cin >> target;

	cout << find_closest(arr,target) << endl;

	return 0;
}
