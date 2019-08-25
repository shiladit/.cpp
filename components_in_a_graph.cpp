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

/* Implementation of UNION_FIND without Path Compression */

#define SIZE (2*n)+1

struct node {
	int parent;
	int rank;
	int no;
	int val;
};

int n;
vector <node> g(30001);

void makeset(int i){
	g[i].val = i;
	g[i].parent = i;
	g[i].no = 1;
	g[i].rank = 0;
}

int find_parent(int u){
	if(g[u].parent == u)
		return u;

	return find_parent(g[u].parent);
}


int main() {

	cin >> n;

	for(int i=1;i<SIZE;i++)
		makeset(i);

	for(int j=0;j<n;j++){
		int u,v;
		cin >> u >> v;

		int p1 = find_parent(u);
		int p2 = find_parent(v);

		if(p1 != p2){
				if(g[p1].rank > g[p2].rank){
					g[p2].parent = p1;
					g[p1].no += g[p2].no;
				}
				else if(g[p1].rank < g[p2].rank){
					g[p1].parent = p2;
					g[p2].no += g[p1].no;
				}
				else{
					g[p2].parent = p1;
					g[p1].rank += 1;
					g[p1].no += g[p2].no;
				}
		}
	}

	pqueue q1;
	pdqueue q2;

	for(int i=1;i<SIZE;i++){
		if(g[i].no != 1 && g[i].parent == i){
			q1.push(g[i].no);
			q2.push(g[i].no);
		}
	}

	cout << q2.top() << " " << q1.top() << endl;
}