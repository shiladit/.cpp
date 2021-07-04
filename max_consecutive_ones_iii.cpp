// leetcode
#include <bits/stdc++.h>
using namespace std;

int calculate(vector <int> &arr, int k)
{
    int n = arr.size();
    int max_len = -INT_MAX;

    /* start with left and right boundary set as 0 at each iteration increase window size and check */
    int l,r,cur_len,zeros;
    l = r = cur_len = zeros = 0;

    /* till right boundary touches the end */
    while(r < n)
    {
	/* if we see a 1, increase window size and keep track of current length */
        if(arr[r] == 1)
        {
            cur_len = (r-l) + 1;
            r++;
        }
        else
        {
	    /* we come here when we see 0 */
            zeros++;
            /* if no. of zeros seen is than equal to k we increase window size */
            if(zeros <= k)
            {
                cur_len = (r-l) + 1;
                r++;
            }
            else
            {
		/* whenever current no. of zeros becomes more than k, we increase left
		boundary of the window till we see a 0, means now window size again becomes == k */
                while(l < arr.size() && arr[l] != 0) l++;

		/* we start our next iteration from the next values of l and r, since they have already been accounted for */
                if(arr[l] == 0)
                {
                    zeros--;
                    l++;
                    r++;
                }
            }
        }

	/* keep track of the max window size */
        if(cur_len > max_len)
            max_len = cur_len;
    }

    return max_len;
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

    int k;
    cin >> k;

    int result = calculate(arr,k);
    cout << result << endl;

    return 0;
}
