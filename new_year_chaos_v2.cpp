#include <iostream>
#include <vector>
using namespace std;

bool check_out_of_range(int index, long val)
{
	if((val - index) > 2)
		return true;
	
	return false;
}

long max(long a, long b)
{
	if(a>b)
		return a;
	else
		return b;
}

long calculate_inversions(vector <long> arr)
{
	long no_of_inv = 0;
	long elements_ooo = 0;
	
	for(int i=0;i<arr.size();i++)
	{
		for(int j=max(0,arr[i]-2);j<i;j++)
		{
			cout << i << " -- " << j << endl;
			if(arr[j] > arr[i])
			{
				no_of_inv++;
			}
		}
	}
	return no_of_inv;
}

int main()
{
	long t;
	cin >> t;
	while(t--)
	{
		long n,temp;
		cin >> n;
		bool chaos = false;
		vector <long> arr;
		for(int i=0;i<n;i++)
		{
			cin >> temp;
			arr.push_back(temp);
			if((chaos == false) && (check_out_of_range(i+1,arr[i])))
			{
				chaos = true;
			}
		}
		if(chaos == false)
		{
			cout << calculate_inversions(arr) << endl;
		}
		else
			cout << "Too chaotic\n";
	}
	return 0;
}
