#include<bits/stdc++.h>
#include <stack>

using namespace std;

void addEdge(vector<int> adj[],int u,int v) {

    adj[u].push_back(v);

}

//Print Function taken from G2G
void printG(vector <int> adj[],int V) {
    for (int v = 0; v < V; ++v)
    {
        cout << "\n Adjacency list of vertex " << v << "\n head ";
        for (auto x : adj[v])
           cout << "-> " << x;
        printf("\n");
    }
}


void bfs(vector <int> adj[],int V,int start){

    int visited[V];

    visited[start] =1; // Visiting the starting vertex

    queue <int> q;
    q.push(start);
    int a;

    cout << "The bfs seq: " ;

    while(!q.empty()) {
        
        a = q.front();
        q.pop();
        cout  << a << " ";

        for(auto x: adj[a]){
            //cout << x << " ";
            
             if(visited[x] == 0) {
                q.push(x);
                visited[x] = 1;
            }
        }
    }
}


void dfs(vector <int> adj[],stack <int> s,int visited[]) {

int a;

while(!s.empty()){
    a=s.top();
    // cout << a << endl;
    // break;

    for(auto x: adj[a])
        if(visited[x] == 0){
            visited[x] =1;
            s.push(x);
            cout << x <<  " "; 
            dfs(adj,s,visited);
            //int b=s.top();
                      
        }

        s.pop();
}

}

int main()
{
    
    int  V = 6 ;
    vector <int> adj[V];

    addEdge(adj, 0, 1);
    addEdge(adj, 1, 2);
    addEdge(adj, 2, 3);
    addEdge(adj, 0, 5);
    addEdge(adj, 5, 4);
    addEdge(adj, 4, 3);

    // printG(adj,V);
    
    int start = 0;
    
    //BFS CALL    
    bfs(adj,V,start);

    cout << "\n-------------------------------------------\n" ;
    
    //DFS CALL
    stack <int> s;
    s.push(start);

    int visited[V];

    for(int u=0;u<V;u++)
        visited[u]=0;

    visited[start]= 1;

    cout << "The dfs seq is : " << start << " ";
    dfs(adj,s,visited);
    cout << endl;
 
    return 0;
}


