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

int arr[100000][100000];
bool flag = false;

int main() {

ll n,k;
cin >> n >> k;

set <ll> evlp;

f(i,0,k){
	ll x;
	cin >> x;
	x = x-1;
	evlp.insert(x);
}

ll u,v,val;

f(i,0,n-1){
	cin >> u >> v >> val;
	u = u-1;
	v = v-1;
	arr[u][v] = val;
	arr[v][u] = val;
}

ll count = 0; // Keeping count of how many envelopes visited till now, if this is equal to k, break

stack <ll> s;
vector <bool> visited(n,false);
ll total_dist = 0;

set <ll> :: iterator it;
it = evlp.begin();

s.push(*it);
visited[*it] = true;

while(!s.empty()){

	ll node = s.top();
	visited[node] = true;
	s.pop();

	for(ll i=0;i<n;i++){
		if(arr[node][i] != 0 && visited[i] == false){
			s.push(i);
			// sudo add-apt-repository \
   "deb [arch=amd64] https://download.docker.com/linux/ubuntu \
   $(lsb_release -cs) \
   stable"
		}
	}
}

cout << total_dist << endl;

}

/* DEBUG

f(i,0,n){
			f(j,0,n)
				cout << arr[i][j] << " ";
			cout << endl;
		}

*/