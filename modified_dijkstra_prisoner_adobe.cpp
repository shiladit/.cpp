/* A directed weighted graph consisting of N nodes was given where at each node there was a hostage.
   A source and destination node were also provided.
   N soldiers started from the source node and each soldier had the job to save exactly one hostage.
   The cost of saving one hostage was the sum of the weights in the path from source node to the node
   where the hostage is held and then to the destination node which the soldier took.
   We had to minimize the total cost of saving all the hostages.*/


#include <bits/stdc++.h>
using namespace std;

#define INF 99999
#define V 5

int choose(vector <int> distance,vector <bool> visited){
	int min_val = INT_MAX;
	int node = -1;

	for(int i=0;i<distance.size();i++){
		if(distance[i] < min_val && !visited[i]){
			min_val=distance[i];
			node = i;
		}
	}
	return node;
}

void print_m (vector <int> distance){

	for(int i=0;i<distance.size();i++){
		cout << distance[i] << " ";
	}
}

int main() {

	int arr[V][V] = {{0,10,5,INF,INF},
					{INF,0,2,1,INF},
					{INF,3,0,9,2},
					{INF,INF,INF,0,4},
					{7,INF,INF,6,0}};

	vector <bool> visited(V,false);

	vector <int> distance(V,INF);

	int start = 0;
	visited[start] = true;
	distance[start] = 0;

	for(int i=0;i<V;i++){
		visited[start] = true;
		for(int j=0;j<V;j++){
			if(start!=j && arr[start][j]!=INF){
				distance[j] = min(distance[j],distance[start] + arr[start][j]);
			}
		}	
		start = choose(distance,visited);
		if(start == -1)
			break;
	}

	cout << "Printing Distance Matrix\n";
	cout << "------------------------\n";

	print_m(distance);
	cout << endl;
}