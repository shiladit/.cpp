#include <iostream>
#include <vector>
#include <set>
#include <cassert>
#include <algorithm>

using namespace std;

vector <vector <int> > final_res;

void countWays(vector <int> result, int val, int index, vector <int> &arr)
{
    if(val == 0)
    {
        /* push to the final result vector */
        final_res.push_back(result);
        return;
    }

    for(int i=index;i<arr.size();i++)
    {        

        /* if duplicates are present, we process the first one, if are able to achieve target
        with it, we push it in final_res, if not we skip. Eitherway we skip similar values after
        it has been processed once */
        if((i>0) && (i>index) && (arr[i] == arr[i-1]))
           continue;

        /* push current element to result vector */
        result.push_back(arr[i]);

        if((val - arr[i]) >= 0)
            countWays(result,val-arr[i],i+1,arr);

        /* backtracking, to try other combinations */
        result.pop_back(); 

    }

    return;
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

    /* sorting will help seggregate duplicates */
    sort(arr.begin(),arr.end());
    vector <int> result;

    int target;
    cin >> target;

    countWays(result,target,0,arr);

    /* o/p */
    for(int i=0;i<final_res.size();i++)
    {
        for(int j=0;j<final_res[i].size();j++)
        {
            cout << final_res[i][j] << ",";
        }
        cout << endl;
    }

    return 0;
}
