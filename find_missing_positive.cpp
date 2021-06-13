// leetcode
#include <iostream>
#include <vector>
using namespace std;

/* Not sure why getting runtime error while submitting,
The idea is to check if element i is in position (i-1),
if not swap. Now after swapping the i-th element may also
not be in correct position, so we process it again by making i--
*/

int find_missing_positive(vector <int> arr)
{
	int highest = 0;

	for(int i=0;i<arr.size();i++)
	{
		if(arr[i] > 0)
		{
			int cur_elem = arr[i];
			if(arr[cur_elem-1] != arr[i])
				swap(arr[i],arr[cur_elem-1]);

			if(arr[i] != (i+1))
				i--;
		}
	}

/* Check which element from first is not in
correct position, return */
	for(int i=0;i<arr.size();i++)
	{
		if(arr[i] != (i+1))
			return (i+1);
	}

	return arr.size();
}

int main()
{
	int n, temp;
	cin >> n;

	vector <int> arr;
	for(int i=0;i<n;i++)
	{
		cin >> temp;
		arr.push_back(temp);
	}

	cout << find_missing_positive(arr) << endl;
	return 0;
}
