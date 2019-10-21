/* KRUSKAL with Union Find is used */

//shiladitya
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#define ll long long
#define f(i,a,b) for(ll i=a;i<b;i++)
#define mod (1000*1000*1000+7)
#define vi vector < int >
#define vb vector < bool >
#define vl vector < ll >
#define vvi vector < vector <int> >
#define vvc vector < vector <char> > 
#define pqueue priority_queue< int >
#define pdqueue priority_queue< int,vi ,greater< int > >

using namespace std;

struct node{
	int parent;
	int val;
};

vector <node> arr(3001);

bool compare(pair <int, pair<int,int> > &a,pair <int, pair<int,int> > &b){
	if(a.first < b.first)
		return true;
	else
		return false;
}

int find(int v){
	if(arr[v].parent == -1)
		return v;
	return	find(arr[v].parent);
}

int main(){
	int n,m;
	cin >> n >> m;

	// Makeset
	f(i,0,n){
		arr[i].parent = -1;
		arr[i].val = i; 
	}

	vector <pair <int,pair <int,int> > > adj;

	f(i,0,m){
		int u,v,w;
		cin >> u >> v >> w;
		u--; v--;
		adj.push_back(make_pair(w,make_pair(u,v)));
	}

	sort(adj.begin(),adj.end(),compare);
	int span_weight = 0;

	f(i,0,m){
		pair <int, pair<int,int> > edge = adj[i]; // Choosing smallest weighted guy

		int x = find(edge.second.first);
		int y = find(edge.second.second);

		// Union Step
		if(x != y){
			arr[x].parent = y;
			span_weight += edge.first;
		}
	}
	cout << span_weight << endl;
}