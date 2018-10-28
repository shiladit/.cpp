#include <bits/stdc++.h>
using namespace std;

bool check_bipartite(int G[5][5],int s){
	
	// vector <int> U;
	// vector <int> V;

	vector <bool> visited(5,false);
	vector <int> color(5,-1); // -1 means no colors are assigned

	queue <int> q;
	q.push(s);
	visited[s] = true;
	color[s] = 1;

	while(!q.empty()){
	
		int top = q.front();
		visited[top] = true;
		q.pop();

		for(int i=0;i<5;i++)
			if(!visited[i] && G[top][i] == 1 && top!=i){
				if(color[top] == 1 && color[i] != 1){
					color[i] = 2;
					q.push(i);
				}
				else if(color[top] == 2 && color[i] != 2){
					color[i] = 1;
					q.push(i);
				}
				else
					return false;
			}

	}

	return true;

}

int main(){
	
	/* BIPARTITE
	int G[5][5] = {{0, 1, 1, 0, 0},
                  {1, 0, 1, 1, 0},
                  {1, 1, 0, 0, 0},
                  {0, 1, 0, 0, 1},
                  {0, 0, 0, 1, 0}};
	*/

	/* NON BIPARTITE
	int G[5][5] = {{0, 1, 0, 0, 1},
                  {1, 0, 1, 0, 0},
                  {0, 1, 0, 1, 0},
                  {0, 0, 1, 0, 1},
                  {1, 0, 0, 1, 0}};
	*/


	// Find Complement of Graph
    for(int i=0;i<5;i++)
    	for(int j=0;j<5;j++){
    		if(G[i][j] == 0)
    			G[i][j] = 1;
    		else
    			G[i][j] = 0;
    	}


    // cout << "Printing Complement of Graph\n";


    // for(int i=0;i<5;i++){
    // 	for(int j=0;j<5;j++)
    // 		cout << G[i][j] << " ";
    // 	cout << endl;
    // }

    int s = 0;

    if(check_bipartite(G,s))
    	cout << "YES\n";
    else
    	cout << "NO\n";
}