#include<iostream>
using namespace std;

#define ll long long

/* Two cases its failing: 
   1. Suppose cost is huge and our yield is less, we unnecassrily run loops till we reach cost.
      Need to write a jump routine for that.
   2. Multiplying two huge numbers isn't fitting in long long. Need to take care of that.
*/

int main()
{
	ll machines, workers, cost, to_make;
	cin >> machines >> workers >> cost >> to_make;

	int pass = 1;
	ll candies_made = machines * workers;
	cout << "Candies_made: " << candies_made << endl;
	ll last_made = 0;

	while(candies_made > 0 && candies_made < to_make)
	{
		/* Handling case where are able to
		make the required amount in the
		next step without spending */
		if((candies_made + last_made) >= to_make)
		{
			cout << pass + 1 << endl;
			return 0;
		}
		ll no_of_resources = (candies_made / cost);
		/* we have to optimally divide the resources
		such that no. of machines is as close to
		no. of workers */
		if(no_of_resources > 0)
		{
			ll total_no_of_resources = machines + workers + no_of_resources;
			ll middle = total_no_of_resources/2;
			if(machines >= middle)
			{
				workers += no_of_resources; // add everything to workers
				candies_made = (candies_made - (no_of_resources * cost)) + (machines * workers);
				last_made = machines*workers;
			}
			else if (workers >= middle)
			{
				machines += no_of_resources;
				candies_made = (candies_made - (no_of_resources * cost)) + (machines * workers);
				last_made = machines*workers;
			}
			else if ((middle > machines) && (middle > workers))
			{
				machines = middle;
				workers = total_no_of_resources - middle;
				candies_made = (candies_made - (no_of_resources * cost)) + (machines * workers);
				last_made = machines*workers;
			}
		}
		else
		{
			candies_made = candies_made + (machines*workers);
			last_made = machines*workers;
		}
		cout << "No of machines: " << machines << " -- " << "No of workers: " << workers << endl;
		cout << "Candies made: " << candies_made << endl;
		++pass;
	}

disp:
	cout << pass << endl;
	return 0;
}
