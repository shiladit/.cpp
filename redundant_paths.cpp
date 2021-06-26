//leetcode
#include <iostream>
#include <vector>
using namespace std;

/* We are implementing Union find to detect cycles */

int parent[1001];

int find_parent(int node)
{
     if(parent[node] == node)
         return node;
     else
         return find_parent(parent[node]);
}

vector<int> findRedundantConnection(vector < vector <int> > &edges)
{
    vector <int> result(2);

    for(int i=0;i<1001;i++)
    {
        parent[i] = i;
    }

    for(int i=0;i<edges.size();i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        if(find_parent(u) != find_parent(v))
        {
            parent[find_parent(v)] = u;
            parent[v] = u;
        }
        else
        {
/* Whenever we find a cycle we update the result vector */
            result[0] = u;
            result[1] = v;
        }
    }

    return result;
}

int main()
{
	int n,u,v;
	cin >> n;
	vector < vector <int> > edges(n, vector <int> (2));

	for(int i=0;i<n;i++)
	{
		cin >> u >> v;
		edges[i][0] = u;
		edges[i][1] = v;
	}

	vector <int> result = findRedundantConnection(edges);
	cout << result[0] << " " << result[1] << endl;

	return 0;
}
