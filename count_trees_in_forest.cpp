#include <bits/stdc++.h>

using namespace std;


int find_trees(vector <vector <int> > arr,vector <bool> visited){

	queue <int> q;

	int count =0;

	for(int i=0;i<arr.size();i++){
		if(visited[i] == false){
			q.push(i);
			visited[i] = true;
			count++;
		}

		while(!q.empty()){
			int node = q.front();
			visited[node] = true;
			q.pop();

			for(int i=0;i<arr.size();i++)
				if(visited[i] == false && arr[node][i] == 1)
					q.push(i);
		}
	}

	return count;
}

int main() {
	int E;
	int V;

	cin >> V >> E;

	vector<vector<int> > arr(V+1,vector <int> (V+1));

	while(E--){
		int a,b;
		cin >> a >> b;

		arr[a][b] = 1;

	}

	vector <bool> visited(V,false);

	cout << find_trees(arr,visited) << endl;
}