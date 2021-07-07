#include <iostream>
#include <vector>
using namespace std;

int calc_prod_subarr(vector <int> &arr)
{
    int n = arr.size();
     
    /* initialize max_ending_here and min_ending_here and max_overall,
    to the first elements of the array */
    int max_ending_here = arr[0];
    int min_ending_here = arr[0];
    int max_overall = arr[0];
    
    for(int i=1;i<n;i++)
    {
    	/* reset */
        if(arr[i] == 0)
        {
            max_ending_here = 0;
            min_ending_here = 0;
        }
        /* if current element is +ve */
        else if(arr[i] > 0)
        {
        	
            if(max_ending_here > 0)
            {
            	/* if max was already positive, this current element will further increase the max value */
                max_ending_here = max_ending_here * arr[i];
            }
            else
            {
            	/* if max is negative, we cant make it bigger by multiplying with the current positive element,
            	so the max ending here is the current positive element */
                max_ending_here = arr[i];
            }
            
            if(min_ending_here < 0)
            {
            	/* if min is negative, multiplying with the current positive element will make min smaller */
                min_ending_here = min_ending_here * arr[i];
            }
            else
            {
            	/* if min is positive, we make min as the current element */
                min_ending_here = arr[i];
            }
        }
        else
        {
            int temp = min_ending_here;

            if(max_ending_here > 0)
            {
            	/* if max is positive, and current element is negative, we can increase min as product of max 
            	and the current element */
                min_ending_here = max_ending_here * arr[i];
            }
            else
            {
            	/* if max is negative, min will be equal to the current negative element */
                min_ending_here = arr[i];
            }

            if(temp < 0)
            {
            	/* if min is negative , and current element is also negative, we can increase max by product of
            	min and current element */
                max_ending_here = temp * arr[i];
            }
            else
            {
            	/* if min is positive, new min will be current element since its negative */
                max_ending_here = arr[i];
            }
        }
        
        /* keep track of max overall */
        max_overall = max(max_overall,max(max_ending_here,min_ending_here));
    }
    
    return max_overall;
}

int main()
{
	int n;
	cin >> n;
	vector <int> arr(n);
	for(int i=0;i<n;i++)
		cin >> arr[i];

	cout << calc_prod_subarr(arr) << endl;

	return 0;
}