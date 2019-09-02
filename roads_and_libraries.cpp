//shiladitya
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
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

ll n,m,c_lib,c_road;

ll dfs(vvi &adj){

	vb visited(100000,false);

	stack <ll> stk;
	int no_comp = 0;
	ll total_size = 0;

	for(int k=0;k<n;k++){
		if(visited[k] == false){
			stk.push(k);
			visited[k] = true;
			no_comp++;
			ll size_of_comp = 0;

			while(!stk.empty()){
				ll node = stk.top();
				stk.pop();

				size_of_comp++;

				for(int i=0;i<adj[node].size();i++)
					if(visited[adj[node][i]] == false){
						stk.push(adj[node][i]);
						visited[adj[node][i]] = true;
					}
			}
			
			total_size += size_of_comp-1;
		}
	}

	// cout << "No of Compo: " << no_comp << endl;
	// cout << "total_size: " << total_size << endl; 

	ll total_cost = (total_size*c_road)+(no_comp*c_lib);

	return total_cost;
}

int main(){
	
	ll q;
	cin >> q;

	while(q--){
		
		cin >> n >> m >> c_lib >> c_road;

		vvi adj(n);

		f(i,0,m){
			int u,v;
			cin >> u >> v;
			u = u-1;
			v = v-1;

			adj[u].push_back(v);
			adj[v].push_back(u);	
		}

		cout << min(dfs(adj),n*c_lib) << endl;
	}	
}