#include <iostream>
using namespace std;

bool can_reach(int * arr, int arr_size)
{
	/* Starting index */
	int index = 0;
	while(index < arr_size)
	{
		/* Max distance I can jump to from the index */
		int max_distance_for_index = index + arr[index];

		int record_index = -1; int max_val = 0;

		/* For each of the jump values within this max
		distance, i check which is the farthest i can
		jump to. I keep track of that particular index,
		since my next jump will start from there */
		for(int x=index+1;x<=max_distance_for_index;x++)
		{
			int jump = x + arr[x];
			if(jump > max_val)
			{
				record_index = x;
				max_val = jump;
			}
		}
		/* If my maximum jumpable distance
		is 0, i.e. i can't move forward, i
		am at a dead end. */
		if(max_val == 0)
			return false;

		/* record_index keeps track of the array
		index from which i can jump the farthest */
		index = record_index;
	}

	/* If i reach end */
	return true;
}

int main()
{
	int n;
	int temp;
	cin >> n;

	int arr[n];
	for(int i=0;i<n;i++)
	{
		cin >> temp;
		arr[i] = temp;
	}

	if(can_reach(arr,n) == false)
	{
		cout << "Can't Reach" << endl;
	}
	else
	{
		cout << "Reached !" << endl;
	}
}
