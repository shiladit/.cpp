#include <bits/stdc++.h>

using namespace std;


class Graph {
	int V; 
	int E;

	list <int> *adj; //Pointer to an integer list
	vector <bool> visited; // Visited boolean array

public:

	Graph(int); // Default Constructor
	void addEdge(int,int);
	void topological_sort(void);
	void topo_util(int,stack <int>*);

};

// Constructor
Graph::Graph(int V){
	this->V = V;
	adj = new list <int> [V];
	this->visited[V]; // Initialized vector
}

void Graph::addEdge(int u,int v){
	adj[u].push_back(v);
}

void Graph::topo_util(int i,stack <int>* stk){
	
	visited[i] = true;

	list <int> :: iterator it;
	for(it = adj[i].begin();it != adj[i].end(); it++){
		if(visited[*it] == false){ 
			topo_util(*it,stk);
		}
	}

	stk->push(i);

}

void Graph::topological_sort(){
	stack <int> stk;

	for(int i=0;i<V;i++)
		visited.push_back(false);

	cout << "The Topolgical Sorting is as follows: " ;

	for(int i=0;i<visited.size();i++)
		if(visited[i] == false){
			topo_util(i,&stk);
		}

	while(!stk.empty()){
		int top = stk.top();
		stk.pop();
		cout << top << " ";
	}
}


int main() {

	int V,E;
	cin >> V >> E;

	Graph g(V);

	while(E--){
		int u,v;
		cin >> u >> v;

		g.addEdge(u,v);
	}

	g.topological_sort();

	cout << endl;

}