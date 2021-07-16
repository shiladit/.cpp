// Leetcode
#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>
#include <cassert>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	cin >> n;

	vector <int> arr(n);

	/* i/p */
	for(int i=0;i<n;i++)
	{
		cin >> arr[i];
	}

	vector < unordered_map <int,int> > vec(n);

	/* minimum sequence length will be 2 */
	int max_seq = 2;

	/* for every element i, we look at all elements(j) less than i,
	we keep track of arr[i] - arr[j] in the map at index[i] of the vector
	This value is further used to compute for future elements */
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<i;j++)
		{
			int val = arr[i] - arr[j];

			/* if difference hasnt been encountered before, we keep track of it
			in the map at index i */
			if(vec[j].find(val) == vec[j].end())
			{
				vec[i][val] = 2;
			}
			else
			/* if similar difference is found in the map at index j, we increase
			the value by 1 in map at index i */
			{
				vec[i][val] = vec[j][val] + 1;

				/* keep track of the max sequence length
				seen so far */
				if(vec[i][val] > max_seq)
				{
					max_seq = vec[i][val];
				}
			}
		}
	}

	cout << max_seq << endl;

	return 0;
}