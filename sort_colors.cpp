#include <iostream>
#include <vector>
using namespace std;

bool compare(int a,int b)
{
	if(a > b)
		return true;
	else
		return false;
}

void sortColors(vector<int> &nums)
{
	for(int i=0;i<nums.size();i++)
	{
		for(int j=i+1;j<nums.size();j++)
		{
			if(compare(nums[i],nums[j]) == true)
			{
				swap(nums[i],nums[j]);
			}
		}
	}
}

void printColors(vector <int> &nums)
{
	for(int i=0;i<nums.size();i++)
	{
		cout << nums[i] << " ";
	}
	cout << endl;
}

int main()
{
	int n, temp;
	cin >> n;

	vector <int> nums;
	for(int i=0;i<n;i++)
	{
		cin >> temp;
		nums.push_back(temp);
	}

	sortColors(nums);
	printColors(nums);

	return 0;
}
