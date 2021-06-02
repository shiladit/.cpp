#include <iostream>
#include <climits>
#include <cassert>
#include <set>
#include <vector>
using namespace std;

/* PARTIALLY PASSED

Approach was first to compute All pair shortest paths
then create a subgraph based on the envelopes. This graph
will have only nodes where envelopes need to be delivered
with all the KC2 paths filled(if there are k nodes with envelopes).
We then calculate MST.

Observations: We need to better handle nodes with Order 1, because
if we visit a node with Order 1, we have to come back the same path.
*/

void print_matrix(vector < vector <int> > matrix)
{
	cout << "DEBUG: printing matrix\n\n";
	int m_size = matrix.size();
	int n_size = matrix[0].size();

	for(int i=0;i<m_size;i++)
	{
		for(int j=0;j<n_size;j++)
		{
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
}

/* Floyd Warshall */
vector < vector <int> >  all_pair_shortest_path(vector <vector <int> > matrix)
{
	int mat_size = matrix[0].size();

	for(int k=0;k<mat_size;k++)
	{
		for(int i=0;i<mat_size;i++)
		{
			for(int j=0;j<mat_size;j++)
			{
				if((matrix[i][j] > (matrix[i][k] + matrix[k][j]))
				 && matrix[i][k] != INT_MAX
				 && matrix[k][j] != INT_MAX)
				{
					matrix[i][j] = matrix[i][k] + matrix[k][j];
				}
			}
		}
	}

	return matrix;
}

/* This routine creates the complete subgraph for envlopes only */
vector < vector <int> > create_envelope_subgraph(vector < vector <int> > computed_distance_matrix,set <int> envelopes)
{
	int subgraph_size = computed_distance_matrix.size();
	vector < vector <int> > subgraph(subgraph_size, vector <int> (subgraph_size));

	for(int i=0;i<subgraph_size;i++)
	{
		for(int j=0;j<subgraph_size;j++)
		{
			if((envelopes.find(i) != envelopes.end()) && (envelopes.find(j) != envelopes.end()))
				subgraph[i][j] = computed_distance_matrix[i][j];
			else
				subgraph[i][j] = INT_MAX;
		}
	}

	return subgraph;
}

int find_min_key(vector <int> key,vector <bool> visited)
{
	int index;
	int min_value = INT_MAX;

	for(int i=0;i<key.size();i++)
	{
		if(visited[i] == false && key[i] < min_value)
		{
			min_value = key[i];
			index = i;
		}
	}
	return index;
}

/* Using PRIM for calculating MST */
int prim_mst(vector < vector <int> > subgraph,set <int> envelopes)
{
	int subgraph_size = subgraph[0].size();
	int envelopes_size = envelopes.size();
	assert(subgraph_size > 0);

	vector <bool> visited(subgraph_size,false);
	vector <int> key(subgraph_size,INT_MAX);
	set <int> :: iterator it;
	it = envelopes.begin();
	key[*it] = 0;

	for(int count=0;count<(envelopes_size-1);count++)
	{
		int u = find_min_key(key,visited);
		visited[u] = true;

		for(int v=0; v<subgraph_size;v++)
		{
			if(subgraph[u][v] && visited[v] == false && subgraph[u][v] < key[v])
			{
				key[v] = subgraph[u][v];
			}
		}
	}

	/* Calculating cumulative sum of weights
	for the Minimum Spanning Tree */
	int sum = 0;
	for(int i=0;i<key.size();i++)
	{
		//cout << key[i] << " ";
		if(key[i] != INT_MAX)
		{
			sum += key[i];
		}
	}

	return sum;
}

int main()
{
	int n,k,temp;
	cin >> n >> k;

	set <int> envelopes;
	for(int i=0;i<k;i++)
	{
		cin >> temp;
		envelopes.insert(temp-1);
	}
	/* Allocate 2-D distance vector matrix */
	vector < vector <int> > initial_distance_matrix(n,vector <int> (n));
	/* initialize distance matrix */
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(i == j)
				initial_distance_matrix[i][j] = 0;
			else
				initial_distance_matrix[i][j] = INT_MAX;
		}
	}

	int u,v,w;
	for(int i=0;i<(n-1);i++)
	{
		cin >> u >> v >> w;
		/* for bidirectional edges insert both ways */
		initial_distance_matrix[u-1][v-1] = w;
		initial_distance_matrix[v-1][u-1] = w;
	}

	//print_matrix(initial_distance_matrix);

	vector < vector <int> > computed_distance_matrix(n,vector <int> (n));
	computed_distance_matrix = initial_distance_matrix;
	computed_distance_matrix = all_pair_shortest_path(computed_distance_matrix);

	//print_matrix(computed_distance_matrix);

	vector < vector <int> > subgraph = create_envelope_subgraph(computed_distance_matrix,envelopes);

	//print_matrix(subgraph);

	cout << prim_mst(subgraph,envelopes) << endl;

	return 0;
}
