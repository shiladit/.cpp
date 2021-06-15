// leetcode
#include <iostream>
#include <vector>
using namespace std;

/* Idea is to find the closest heater from every house,
we do this by sorting the list of heaters and doing 
a modified binary search on it.

** Maybe this is possible using lower and upper bounds on a set also.(check heaters_v2.cpp for map)

Next we check which is the farthest heater from any house,
thats the answer
*/

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
	
	/* when i > j and we haven't found the value, control reaches here.
	It can only mean we have only 1 element, so print the middle element
	from the previous iteration, which is the only element */
	return arr[middle];
}

int main()
{
	int n,temp;
	cin >> n;
	vector <int> houses;

	for(int i=0;i<n;i++)
	{
		cin >> temp;
		houses.push_back(temp);
	}

	int m;
	cin >> m;
	vector <int> heaters;

	for(int i=0;i<m;i++)
	{
		cin >> temp;
		heaters.push_back(temp);
	}

	sort(heaters.begin(),heaters.end());
	
	int max_close = -INT_MAX;
        
	for(int i=0;i<houses.size();i++)
	{
		int closest = find_closest(heaters,houses[i]);
		int distance = abs(houses[i] - closest);
            
		if(distance > max_close)
			max_close = distance;
            
            // cout << "For house: " << houses[i] << " Closest heater: " << closest << endl;
	}
        
        return max_close;
	
	return 0;
}
