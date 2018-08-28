#include <bits/stdc++.h>

using namespace std;

bool in(int x,int y,int n){

    return x>=0 && x<n && y >=0 && y <n;
}

int knight_tour(int a,int b,int n){
    bool visited[30][30] = {{false}};
    int moves[30][30] = {{0}};

    visited[0][0] = true;

    int dx[8]= {a,a,-a,-a,b,b,-b,-b};
    int dy[8]= {b,-b,-b,b,a,-a,a,-a};

    queue <pair <int,int> > q;

    q.push(make_pair(0,0));

    while(!q.empty()){
        pair <int,int> p = q.front();
        int x= p.first;
        int y= p.second;
        q.pop();

        for(int i=0;i<8;i++){
            if(in(x+dx[i],y+dy[i],n)){

                if(!visited[x+dx[i]][y+dy[i]]){
                    visited[x+dx[i]][y+dy[i]] =true;
                    moves[x+dx[i]][y+dy[i]] = moves[x][y]+1;
                    q.push(make_pair(x+dx[i],y+dy[i]));
                }
            }
        }
    } 
    
    if(!visited[n-1][n-1])
        return -1;
    else
        return moves[n-1][n-1];

}


int main(){

    int n;
    cin >> n;

    for(int i=1;i<n;i++){
        for(int j=1;j<n;j++){
            cout << knight_tour(i,j,n) << " " ;
        }
        cout << endl;
    }
}