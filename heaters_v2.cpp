// leetcode

/* TLE, 20/30 test cases Passed!
Apparently finding lower bound is a costly 
operation than we think it is,
Check heaters.cpp for binary search method */

#include <iostream>
#include <vector>
#include <set>
using namespace std;

int find_closest(set <int> heaters, int target)
{
	set <int> :: iterator it;

	it = heaters.begin();
	if(target <= *it)
		return *it;

	it = heaters.end();
	it--;
	if(target >= *it)
		return *it;


	int a,b;
	it = heaters.lower_bound(target);
	a = *it;
	if(it != heaters.begin() || it != heaters.end())
	{
		it--;
		b = *it;
	}

	if(abs(target-a) > abs(target-b))
		return b;
	else
		return a;
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
	set <int> heaters;

	for(int i=0;i<m;i++)
	{
		cin >> temp;
		heaters.insert(temp);
	}

	int max_close = -INT_MAX;
        
	for(int i=0;i<houses.size();i++)
	{
		int closest = find_closest(heaters,houses[i]);
		int distance = abs(houses[i] - closest);
            
		if(distance > max_close)
			max_close = distance;
	}

	cout << max_close << endl;
        
	return 0;
}
