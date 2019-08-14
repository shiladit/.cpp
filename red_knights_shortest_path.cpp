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

int moves[200][200] = {{0}};
bool visited[200][200] = {{false}};
vector <string> route[200][200] = {{}};

string dir[6] = {"UL","UR","R","LR","LL","L"};
int movex[6] = {-2,-2,0,2,2,0};
int movey[6] = {-1,1,2,1,-1,-2};


bool issafe(int a,int b,int n){
	if(a>=0 && a<n && b>=0 && b<n)
		return true;
	else
		return false;
}

int main() {

int n;
cin >> n;

int startx,starty,endx,endy;
cin >> startx >> starty >> endx >> endy;

queue <pair <int,int> > q;
q.push(make_pair(startx,starty));
visited[startx][starty] = true;


while(!q.empty()){

	pair <int,int> p = q.front();
	int x = p.first;
	int y = p.second;
	q.pop();

	for(int i=0;i<6;i++){
		if(issafe(x+movex[i],y+movey[i],n) && visited[x+movex[i]][y+movey[i]] == false){
			// cout << "Hi" << endl;
			visited[x+movex[i]][y+movey[i]] = true;
			moves[x+movex[i]][y+movey[i]] = 1+ moves[x][y];

			vector <string> s= route[x][y];

			// Appending previous moves till that point to the new route
			for(int z=0;z<s.size();z++){
				route[x+movex[i]][y+movey[i]].push_back(s[z]);				
			}

			//Appending last taken move to reach that point
			route[x+movex[i]][y+movey[i]].push_back(dir[i]);
			q.push(make_pair(x+movex[i],y+movey[i]));

			// cout << x+movex[i] << "," << y+movey[i] << " --> " << dir[i] << endl;
		}
	}

}

if(!moves[endx][endy])
	cout << "Impossible" << endl;
else{
	cout << moves[endx][endy] << endl;
	
	vector <string> s = route[endx][endy];
	for(int i=0;i<s.size();i++)
		cout << s[i] << " ";

	cout << endl;

	}
}

/*DEBUG*/
// for(int i=0;i<n;i++){
// 	for(int j=0;j<n;j++){
// 		cout << moves[i][j] << " ";
// 	}
// 	cout << endl;
// }