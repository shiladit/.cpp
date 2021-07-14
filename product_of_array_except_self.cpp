// leetcode
#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

vector <int> productExceptSelf(vector <int> &arr)
{
	int zeros = 0;
	int n = arr.size();
	assert(n >= 0);
	
	int product = 1;

	for(int i=0;i<n;i++)
	{
		/* count no. of 0's */
		if(arr[i] == 0)
		{
			zeros++;
		}
		/* if not 0, add it to the product */
		else
		{
			product =  product * arr[i];
		}
	}

	vector <int> result;

	/* if there is only 1 zero, then all elements will value equal to 0
	except at index with elem 0 in i/p, it will be equal to product */
	if(zeros == 1)
	{
		for(int i=0;i<n;i++)
		{
			if(arr[i] == 0)
				result.push_back(product);
			else
				result.push_back(0);
		}
	}
	/* if there are more than 1 zero, then everything in o/p will be 0 */
	else if (zeros > 1)
	{
		for(int i=0;i<n;i++)
		{
			result.push_back(0);
		}
	}
	/* normal case : product/arr[i] */
	else
	{
		for(int i=0;i<n;i++)
		{
			result.push_back(product/arr[i]);
		}
	}

	return result;
}

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

	vector <int> result = productExceptSelf(arr);

	/* o/p */
	for(int i=0;i<result.size();i++)
	{
		cout << result[i] << " ";
	}
	cout << endl;

	return 0;
}
