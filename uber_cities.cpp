#include <bits/stdc++.h>
using namespace std;

void print_matrix(vector <vector <int> > arr){
	for(int i=1;i<arr.size();i++){
		for(int j=1;j<arr[i].size();j++)
			cout << arr[i][j] << " ";
		cout << endl;
	}
}

int pick(vector <bool> visited,vector <int> distance){
	
	int min_val = INT_MAX;
	int min_node = -1;

	for(int i=1;i<distance.size();i++){
		if(distance[i] < min_val && visited[i] == false ){
			min_val = distance[i];
			min_node = i;
		}
	}

	return min_node;
}

int run_dijkstra(vector <vector <int> > dist,int start,int end){
	int source = start;
	int terminal = end;

	vector <bool> visited(dist.size(),false);
	vector <int> distance(dist.size(),99999);
	distance[source] = 0;

	int last_picked = -1;

	for(int count=1;count<dist.size();count++){
		int picked = pick(visited,distance);
		last_picked = picked;
		visited[picked] = true;

		for(int j=1;j<dist[picked].size();j++){
			if(dist[picked][j] != 0 && (distance[picked] + dist[picked][j] < distance[j]))
				distance[j] = distance[picked] + dist[picked][j];
		}
	}
	
	int sum =0;

	// for(int i=1;i<distance.size();i++)
		// cout << distance[i] << " ";
	for(int i=1;i<distance.size();i++)
		sum = sum + distance[i];
	

	if(last_picked == terminal)
		return sum;

	else{

		for(int i=1;i<visited.size();i++)
			visited[i] = false;

		for(int i=1;i<distance.size();i++)
			distance[i] = 99999;

		distance[last_picked] = 0;

		for(int count=1;count<dist.size();count++){
		int picked = pick(visited,distance);
		last_picked = picked;
		visited[picked] = true;

		for(int j=1;j<dist[picked].size();j++){
			if(dist[picked][j] != 0 && (distance[picked] + dist[picked][j] < distance[j]))
				distance[j] = distance[picked] + dist[picked][j];
			}
		}
		
		sum = sum + distance[terminal];
		return sum; 

		// cout << distance[terminal] << endl;
	}

}





int main(){
	int n,m;
	cin >> n >> m;

	vector <vector <int> > dist(n+1,vector <int> (n+1));

	int u,v,cost;

	for(int i=0;i<m;i++){
		cin >> u >> v >> cost;
		dist[u][v] = cost;
		dist[v][u] = cost;
	}

	// print_matrix(dist);

	cout << run_dijkstra(dist,1,n) << endl;

}