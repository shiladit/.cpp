/* 

Cycle finding in a Directed Graph
---------------------------------

If Cycle is found, print it
If Cycle is not found , print 0
If multiple Cycles are found, print any one 


SAMSUNG IITMadras 2019 Placement Question.. 

No use of STL allowed

*/

#include <iostream>

using namespace std;

int arr[1000][1000]; //Connectivity Matrix
int cycle_endpt = -1;
int j =0 ;

bool dfs(int index,bool* visited_l,int* cycle,int V){

	if(visited_l[index] == true){
		cycle_endpt = index;
		return true;
	}
	else{
		visited_l[index] = true;
		cycle[j++] = index;
	}

	for(int i=0;i<V;i++){

		if(arr[index][i] == 1){
			return dfs(i,visited_l,cycle,V);
		}
	}

	return false;
}

int main() {

	int V,E;
	cin >> V >> E;

	while(E--){
		int s,t;
		cin >> s >> t;

		arr[s][t] = 1; 
	}

	bool visited_g[V];
	fill(visited_g,visited_g+V,false);
	
	for(int i=0;i<V;i++){
		if(visited_g[i] == false){
			bool visited_l[V];
			cycle_endpt = -1;
			int cycle[V];
			
			fill(cycle,cycle+V,-1);
			fill(visited_l,visited_l+V,false);

			j = 0;

			bool flag= dfs(i,&visited_l[0],&cycle[0],V);

			if(flag){
				cout << "Cycle is present\n";
				bool turn = false;

				for(int i=0;i<V;i++){
					if(cycle[i] == cycle_endpt)
						turn = true;
					if(turn == true && cycle[i] != -1)
						cout << cycle[i] << " ";
				}
				cout << endl;
				return -1;
				}
			
			//Updating the global visited vector
			for(int i=0;i<V;i++){
				if(visited_l[i] == true)
					visited_g[i] = true;
			}
		}		
	}

	cout << "0\n";
}
