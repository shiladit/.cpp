//shiladitya
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
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

int adj[100][100];
vector <int> count1(100,0);
vector <bool> visited(100,false);

int n,m;

void dfs(int start){

	count1[start] = 1;

	for(int i=0;i<n;i++){
		if(adj[start][i] == 1 && visited[i] == false){
			visited[i] = true;
			dfs(i);
			count1[start] = count1[start] + count1[i];
		}
	}
}


int main(){
	
	cin >> n >> m;

	for(int i=0;i<m;i++){
		int u,v;
		cin >> u >> v;
		u = u-1;
		v = v-1;
		adj[u][v] = 1;
		adj[v][u] = 1;
	}

	visited[0] = true;
	dfs(0);


	// for(int i=0;i<n;i++)
	// 	cout << "Node " << i << " has size: " << count1[i] << endl;

	int max_size = count1[0];

	int j=1;
	int count = 0;

	while(j<n){
		if((max_size-count1[j])%2 == 0){
			count++;
			max_size = max_size = count1[j];
		}
		j++;
	}

	cout << count << endl;	
}