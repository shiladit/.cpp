//shiladitya
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
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

ll n,k;
int arrx[8]= {0,1,1,1,0,-1,-1,-1};
int arry[8]= {1,1,0,-1,-1,-1,0,1};

bool issafe(int x,int y){
	if(x>=1 && x<=n && y>=1 && y<=n)
		return true;
	else
		return false;
}

int find_moves(int q_x,int q_y,set <pair <ll,ll> > s){
	int count = 0;

	for(int i=0;i<8;i++){
		int x = q_x;
		int y = q_y;
		
		while(s.find(make_pair(x,y)) == s.end() && issafe(x,y)){ // Unless I am not hitting an obstacle
			x = x + arrx[i];
			y = y + arry[i];
			count++;
		}
	}
	count = count-8; // For 8 directions I am counting 1 extra time each

	return count;
}

int main(){

	cin >> n >> k;

	ll q_x,q_y;
	cin >> q_x >> q_y;

	set <pair <ll,ll> > obs;

	f(i,0,k){
		ll x,y;
		cin >> x >> y;
		obs.insert(make_pair(x,y));
	}
	
	cout << find_moves(q_x,q_y,obs) << endl;
}