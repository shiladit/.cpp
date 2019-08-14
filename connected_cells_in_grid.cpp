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

int arr[10][10];
bool visited[10][10] = {{false}};

void print_mat(int n,int m) {

f(i,0,n){
    f(j,0,m){
        cout << arr[i][j] << " "; 
        }
    cout << endl;
    }
}

bool issafe(int a,int b,int n,int m){
    if(a>=0 && a<n && b>=0 && b<m)
        return true;
    else
        return false;
}

int movex[8] ={1,0,1,-1,-1,-1,0,1};
int movey[8] ={0,1,1,1,0,-1,-1,-1}; 

int main() {

int n,m;
cin >> n >> m;

f(i,0,n)
    f(j,0,m){
        cin >> arr[i][j]; 
    }

// print_mat(n,m);

int max_size = 0;    

f(i,0,n)
    f(j,0,m){
        if(visited[i][j] == false && arr[i][j] == 1){

            int count = 1;
            queue <pair <int,int> > q;
            q.push(make_pair(i,j));
            visited[i][j] = true;


            while(!q.empty()){
                pair <int,int> p = q.front();
                int x = p.first;
                int y = p.second;

                q.pop();

                for(int z=0;z<8;z++){
                    if(issafe(x+movex[z],y+movey[z],n,m) && visited[x+movex[z]][y+movey[z]] == false && arr[x+movex[z]][y+movey[z]] == 1){
                        visited[x+movex[z]][y+movey[z]] = true;
                        q.push(make_pair(x+movex[z],y+movey[z]));
                        count++;
                    }
                }
            }

            if(count > max_size)
                max_size = count;

            
        }
    }

    cout << max_size << endl;

}



/*DEBUG

for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
        cout << << endl;

cout << << << endl;

*/

