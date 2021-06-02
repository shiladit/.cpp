#include <iostream>
#include <cassert>
#include <map>
using namespace std;

#define MAX_VAL 999999
int value[101];

/* We build-up the solution, starting index is 1.
We can go anywhere between 2 to 7 using just 1 move.
if there is a ladder in between, we can go the other end
of the head of the ladder using the same no. of moves as the
no. of the moves required to reach the tail of the ladder.
Similarly when we reach a snake's head we can now reach the
snake's tail in the same no. of moves. This maybe less than
the current no. of moves to reach snake's tail, so we update
that and continue evaluating from the snake's tail (again).
*/

/* DEBUG function */
void print_moves()
{
	for(int i=1;i<101;i++)
	{
		cout << value[i] << " ";

		if(i % 10 == 0)
			cout << endl;
	}
}

void compute(map <int,int> ladders, map <int,int> snakes)
{
	/* Initialize the value matrix to MAX_VAL,
	except for the starting index */
	for(int i=1;i<101;i++)
	{
		if(i == 1)
			value[i] = 0;
		else
			value[i] = MAX_VAL;
	}

	/* Starting index*/
	int cur_index = 1;
	/* 6 consecutive snakes mean no solution,
	so we keep track of that */
	int snakes_6 = 0;

	while(cur_index < 101)
	{
		int cur_min = value[cur_index];
		/* if the previous value before me was a ladder,
		then cur_min will remain same as before, since we
		are adding 1 to cur_min later, to compensate for that
		we decrease cur_min here by 1 */
		if(ladders.find(cur_index-1) != ladders.end())
			cur_min -= 1;

		for(int i=cur_index+1;i<cur_index+7;i++)
		{
			/* Unreachable */
			if(snakes_6 >= 6)
			{
				value[100] = -1;
				return;
			}

			value[i] = min(1 + cur_min, value[i]);
			if(value[i] < cur_min)
			{
				cur_min = value[i];
				/* we have a local minima here,
				means we have visited this before,
				it must be the head of a ladder that
				we had seen before, our choices need
				evaluation from this point again.
				-6 is a hack, since we anyway increase
				cur_index by +6 after every loop */
				cur_index = i-6;
				break;
			}

			if(ladders.find(i) != ladders.end())
			{
				int j = ladders[i];
				value[j] = min(value[i],value[j]);
			}
			else if(snakes.find(i) != snakes.end())
			{
				/* snake seen */
				snakes_6++;

				int j = snakes[i];
				if(value[j] > value[i])
				{
					value[j] = value[i];
					cur_index = j - 6 ;
					break;
				}
			}
			else
			{
			/* no snake seen, so we make 0 */
				snakes_6 = 0;
			}
		}
	/* this is triggered after every loop */
		cur_index += 6;
	}

	return;
}

int main()
{
	int t;
	cin >> t;
	assert(t<=10);

	while(t--)
	{
		int n;
		cin >> n;
		map <int,int> ladders;
		int u,v;

		for(int i=0;i<n;i++)
		{
			cin >> u >> v;
			ladders[u] = v;
		}

		int m;
		cin >> m;
		map <int,int> snakes;

		for(int i=0;i<m;i++)
		{
			cin >> u >> v;
			snakes[u] = v;
		}

		compute(ladders,snakes);
		/* DEBUG
		print_moves();
		*/

		int result = value[100];
		if(result == MAX_VAL)
			cout << "-1" << endl;
		else
			cout << value[100] << endl;
	}

	return 0;
}
