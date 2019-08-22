//shiladitya
#include <bits/stdc++.h>
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


int main() {
	int t;
	cin >> t;

	while(t--){
		int n,m;
		cin >> n >> m;

		int arr[n][n];
		f(i,0,n)
			f(j,0,n)
				arr[i][j] = 0;

		f(i,0,m){
			int u,v;
			cin >> u >> v;

			// Filling up adjacency matrix
			arr[u-1][v-1] = 1;
			arr[v-1][u-1] = 1;
		}

		int start;
		cin >> start;
		start = start - 1;

		vi distance(n,INT_MAX);
		vb visited(n,false);

		queue <int> q;

		distance[start] = 0;
		visited[start] = true;
		q.push(start);

		while(!q.empty()){

			int elem = q.front();
			q.pop();

			f(i,0,n){
				if(arr[elem][i] == 1 && visited[i] == false){
					q.push(i);
					visited[i] = true;
					distance[i] = distance[elem] + 6;
				}
			}
		}

		f(i,0,n){

			if(i!=start){	
				if(distance[i] == INT_MAX)
					cout << "-1" << " ";
				else
					cout << distance[i] << " ";
			}
		}
		cout << endl;
		
	}
}

/* DEBUG

f(i,0,n){
			f(j,0,n)
				cout << arr[i][j] << " ";
			cout << endl;
		}

*/