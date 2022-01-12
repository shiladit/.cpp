#include <iostream>
#include <vector>
using namespace std;

int find_subarray(vector <int> &arr)
{
	/* find max element from the array */

	int max_ele = 0;

	for(int i=0;i<arr.size();i++)
	{
		if(arr[i] > max_ele)
			max_ele = arr[i];
	}

	int cm = 1;

	for(int i=0;i<arr.size()-1;i++)
	{
		if((arr[i] == arr[i+1]) && arr[i] == max_ele)
		{
			int count = 1;

			for(int j=i+1;j<arr.size();j++)
			{
				if(arr[j] == max_ele)
				{
					count++;
					i++;
				}
				else
					break;
			}

			if(count > cm)
				cm = count;
		}
	}

	return cm;
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

	cout << find_subarray(arr) << endl;

	return 0;
}