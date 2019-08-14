//shiladitya
#include <bits/stdc++.h>
#define ll long long
#define f(i,a,b) for(ll i=a;i<b;i++)
#define mod (1000*1000*1000+7)
#define vi vector < int >
#define vl vector < ll >
#define pqueue priority_queue< int >
#define pdqueue priority_queue< int,vi ,greater< int > >

using namespace std;

vector <bool> visited(1000,false);
vector <int> sum_arr(1000,0);
vector <int> weights(1000,0);
vector <int> edges[1000];
int n;

int dfs(int node){

	if(visited[node] == true)
		return 0;

	if(edges[node].size() == 0){
		sum_arr[node]=weights[node];
		visited[node] = true;
		// cout << "Hi\n";
		return sum_arr[node];
	}

	else {
		vector <int> :: iterator it;
		visited[node] = true;

		int sum = weights[node];

		for(it = edges[node].begin(); it != edges[node].end() ;  it++){
			int k = *it;
			sum = sum + dfs(k);
		}

		sum_arr[node] = sum;
		return sum_arr[node];
	}
}



int main() {

cin >> n;

int sum =0;

for(int i=1;i<=n;i++){
	int x;
	cin >> x;
	weights[i] = x; 
	sum += x;
}

vector <pair<int,int> > v;

for(int i=0;i<(n-1);i++) // n-1 times the loop will iterate
{
	int a,b;
	cin >> a >> b;
	edges[a].push_back(b);
	edges[b].push_back(a);
	v.push_back(make_pair(a,b));
}


dfs(1);

int max_diff = INT_MAX;

for(int i=0;i<v.size();i++){
	pair <int,int> p = v[i];
	int x = p.first;
	int y = p.second;
	int min_val = min(sum_arr[x],sum_arr[y]);

	if(abs(min_val-(sum-min_val)) < max_diff)
		max_diff = abs(min_val-(sum-min_val));	
}

cout << max_diff << endl;
}


