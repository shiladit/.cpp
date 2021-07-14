// Hackerrank
#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>
#include <queue>
#include <stack>
#include <climits>
#include <cassert>
using namespace std;

#define ll long long

vector <int> maxSlidingWindow(vector <int> &nums,int k)
{
	priority_queue <pair <int,int> > PQ;
    vector <int> result;

    for(int i=0;i<k-1;i++)
    {
        PQ.push(make_pair(nums[i],i));
    }

    /* Look at last k elements and check if current element is within (i-k)+1;
    if not keep popping untill we satisfy the bound */
    for(int i=k-1;i<(nums.size());i++)
    {

        PQ.push(make_pair(nums[i],i));

        while((PQ.empty() == false) and (PQ.top().second < ((i-k)+1)))
            PQ.pop();

        result.push_back(PQ.top().first);
    }

    return result;
}

int main()
{
	int n,k;
	cin >> n;
	vector <int> nums(n);

	for(int i=0;i<n;i++)
		cin >> nums[i];

	cin >> k;

	vector <int> final_res = maxSlidingWindow(nums,k);

	for(int i=0;i<final_res.size();i++)
		cout << final_res[i] << " ";
	cout << endl;

	return 0;
}