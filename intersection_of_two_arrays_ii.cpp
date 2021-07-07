#include <iostream>
#include <vector>
#include <map>
using namespace std;

vector <int> intersect(vector <int> &nums1, vector <int> &nums2)
{
	vector <int> result;
	map <int,int> mp;

	for(int i=0;i<nums1.size();i++)
	{
		mp[nums1[i]]++;
	}

	for(int i=0;i<nums2.size();i++)
	{
		if(mp.find(nums2[i]) != mp.end())
		{
			if(mp[nums2[i]] > 0)
			{
				mp[nums2[i]]--;
				result.push_back(nums2[i]);
			}
		}
	}

	return result;
}

int main()
{
	int n;
	cin >> n;
	vector <int> arr_1(n);
	
	for(int i=0;i<n;i++)
		cin >> arr_1[i];

	int m;
	cin >> m;
	vector <int> arr_2(m);

	for(int i=0;i<m;i++)
		cin >> arr_2[i];

	vector <int> result = intersect(arr_1,arr_2);

	for(int i=0;i<result.size();i++)
		cout << result[i] << " ";
	cout << endl;

	return 0;
}