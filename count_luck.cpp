//shiladitya
#include <bits/stdc++.h>
#define ll long long
#define f(i,a,b) for(ll i=a;i<b;i++)
#define pb push_back
#define mp make_pair
#define mod (1000*1000*1000+7)
#define vi vector < int >
#define vl vector < ll >
#define pqueue priority_queue< int >
#define pdqueue priority_queue< int,vi ,greater< int > >

using namespace std;

char arr[100][100];
int decision[100][100];
bool visited[100][100];
int n,m;
int movex[4] = {-1,1,0,0};
int movey[4] = {0,0,-1,1};

bool issafe(int x,int y){
  if(x >=0 && x<n && y >=0 && y <m)
    return true;
  else
    return false;
}

int neighbours(int x,int y){

    int count = 0;

    for(int i=0;i<4;i++){
      if(issafe(x+movex[i],y+movey[i]) && arr[x+movex[i]][y+movey[i]] == '.' && visited[x+movex[i]][y+movey[i]] == false)
        count++;
    }

return count;
}

int main() {
 
  int t;
  cin >> t;
  while(t--){
  
    cin >> n >> m;

    int startx = -1;
    int starty = -1;

    int endx = -1;
    int endy = -1;

    f(i,0,n)
      f(j,0,m){
        char c;
        cin >> c;
        arr[i][j] = c;

        if(c == 'M'){
          startx =i;
          starty =j;
        }

        if(c == '*'){
          endx =i;
          endy= j;
        }

        //mandate
        decision[i][j] = 10000;
        visited[i][j] = false;
      }

    int k;
    cin >> k;


    queue<pair<pair<int,int>,int> > q;

    visited[startx][starty] = true;
    q.push(make_pair(make_pair(startx,starty),0));

    while(!q.empty()){

      pair<pair<int,int>,int> p = q.front();
      q.pop();

      // decision[p.first.first][p.first.second] = p.second ;

      cout << p.first.first << "," << p.first.second << "  decision: " << p.second << endl;

      // if(arr[p.first.first][p.first.second] == '*'){
      //   cout << p.second << endl;
      //   break;
      // }

      // f(i,0,4){
      //   if(issafe(p.first.first+movex[i],p.first.second+movey[i]) && visited[p.first.first+movex[i]][p.first.second+movey[i]] == false && arr[p.first.first+movex[i]][p.first.second+movey[i]] != 'X'){
      //     visited[p.first.first+movex[i]][p.first.second+movey[i]] = true;

    if(neighbours(p.first.first,p.first.second) >= 2){
      cout << "neighbours " << p.first.first << "," << p.first.second << " --> " << neighbours(p.first.first,p.first.second) << endl;
      q.push(make_pair(make_pair(p.first.first+movex[i],p.first.second+movey[i]),1+p.second));
    }
    else
      q.push(make_pair(make_pair(p.first.first+movex[i],p.first.second+movey[i]),p.second));
  }
      
    }


  }


  // for(int i=0;i<n;i++){
  //   for(int j=0;j<m;j++)
  //     cout << decision[i][j] << " ";

  //   cout << endl;
  // }


}