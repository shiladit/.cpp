#include<bits/stdc++.h>

using namespace std;

vector <long> arr[100001];
vector <bool> visited(100001,false);


//Getting TLE

void print(vector <long> arr[],int V){
    
    for (int v = 0; v < V; ++v)
    {
        cout << "\n Adjacency list of vertex " << v << "\n head ";
        for (auto x : arr[v])
           cout << "-> " << x;
        printf("\n");
    }
}

void DFS_util(int i) {
    vector <long> ::iterator it;
    
    for(it = arr[i].begin();it != arr[i].end();it++){
        if(visited[*it] == false){
            visited[*it] = true;
            DFS_util(*it);
        }
    }

    
}


int main() {
    long q,n,m,c_lib,c_road;
    cin >> q;
  
    
    while(q) {
        cin >> n >> m >> c_lib >> c_road;
        long u,v;
       
        
        for(long i=0;i<m;i++){
            cin >> u >> v;    
            arr[u].push_back(v);
            arr[v].push_back(u);
        }
        
        // print(arr,n+1);



        std::fill(visited.begin(), visited.end(), false);

        
        int prev_count =0;
        long sum =0;

        for(int i=1;i<n+1;i++){
            
            if(visited[i] == false) {
                
                
                visited[i] = true; 
                DFS_util(i); 
                int count=0;
                for(int i=1;i<n+1;i++){
                    if(visited[i] == 1)
                    count++;
                }


                long cost1 = (count-prev_count)*c_lib;
                long cost2 = (count-prev_count-1)*c_road + c_lib;

                if(m==0)
                    cost2=INT_MAX;

                // cout << cost1 << " ^^ " << cost2 << endl;

                if(cost1 > cost2)
                    sum += cost2;
                else
                    sum += cost1;

                prev_count = count;
                
            }
                
        }

        cout << sum << endl;
                
        q--;
        
    }
    
}