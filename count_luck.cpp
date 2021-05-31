#include <iostream>
#include <queue>
using namespace std;

#define dim 100
#define viability(index_1,index_2) isSafe(index_1,index_2) && \
		(visited[index_1][index_2] == false) && \
		(arr[index_1][index_2] != 'X') \

int n,m;
int arr[dim][dim];
int visited[dim][dim];
int move_x[4] = {-1,1,0,0};
int move_y[4] = {0,0,-1,1};

struct node {
	int x_val;
	int y_val;
	int decisions; // no of decisions made till this point (x,y)
};

bool isSafe(int x,int y)
{
	if(x >=0 && x<n && y >=0 && y <m)
		return true;
	else
		return false;
}

/* this function returns the no. of viable
neighbours for a given index */
int find_num_neigh(int x, int y)
{
	int count = 0;

	for(int i=0;i<4;i++)
	{
		int a = x + move_x[i];
		int b = y + move_y[i];
		if(viability(a,b))
		{
			count++;
		}
	}
	return count;
}

node* alloc_node(int x,int y)
{
	node* temp = (node*)malloc(sizeof(node));
	temp->x_val = x;
	temp->y_val = y;
	/* we are not initializing decisions */
	return temp;
}

int main()
{
	int t;
	cin >> t;

	while(t--)
	{
		int start_x,start_y,port_x,port_y;
		cin >> n >> m;

		for(int i=0;i<n;i++)
		{
			string s;
			cin >> s;

			for(int j=0;j<s.length();j++)
			{
				arr[i][j] = s[j];
				/* initialize visited array */
				visited[i][j] = false;

				if(s[j] == 'M')
				{
					start_x = i;
					start_y = j;
				}

				if(s[j] == '*')
				{
					port_x = i;
					port_y = j;
				}
			}
		}

		int k;
		cin >> k;

		int answer = 0;

		queue <node *> q;
		node* start_node = alloc_node(start_x,start_y);
		start_node->decisions = 0; /* no decisions has been made yet */

		q.push(start_node);
		visited[start_x][start_y] = true;

		while(!q.empty())
		{
			node* temp = q.front();
			q.pop();

			/* if I have reached portkey, store answer and break out */
			if((temp->x_val == port_x) && (temp->y_val == port_y))
			{
				answer = temp->decisions;
				break;
			}

			/* Calculate no of viable path from the index */
			int no_of_viable_paths = find_num_neigh(temp->x_val, temp->y_val);

			/* Compute for neighbours reachable from current indices */
			for(int i=0;i<4;i++)
			{
				int off1 = temp->x_val + move_x[i];
				int off2 = temp->y_val + move_y[i];

				if(viability(off1,off2))
				{
					node* new_temp = alloc_node(off1,off2);;

					/* If no of paths from an index is more than 1,
					we increase the decision value, since we are
					essentially making a decision here */
					if(no_of_viable_paths > 1)
						new_temp->decisions = temp->decisions + 1;
					else
						new_temp->decisions = temp->decisions ;

					/* insert into queue */
					q.push(new_temp);
					visited[off1][off2] = true;
				}
			}
		}
		(answer == k) ? cout << "Impressed\n" : cout << "Oops!\n";
	}
}
