#include <bits/stdc++.h>
using namespace std;

int GLOB_MAX = -INT_MAX;

bool isSafe(int x,int y,int n,int m){
    if(x >=0 && x <n && y>=0 && y < m)
        return true;
    else
        return false;
}

int main() {
	int t;
	cin >> t;
	
	while(t--){
	    int n,m,temp;
	    cin >> n >> m;

	    GLOB_MAX = -INT_MAX;
	    
	    int arr[n][m];
	    
	    for(int i=0;i<n;i++)
	        for(int j=0;j<m;j++){
	            cin >> temp;
	            arr[i][j] = temp;
	        }
	        
	    int result[n][m];
	    
	    for(int i=0;i<n;i++){
	        result[i][0] = arr[i][0];
	        GLOB_MAX = max(GLOB_MAX,arr[i][0]);
	    }
	        
	   int arr_x[3] = {-1,1,0 };
	   int arr_y[3] = {-1,-1,-1};
	    
	   for(int j=1;j<m;j++)
	    for(int i=0;i<n;i++){
	        int max_val = -INT_MAX;
	        for(int k=0;k<3;k++){
	            if(isSafe(i+arr_x[k],j+arr_y[k],n,m)){
	                max_val = max(max_val,arr[i][j] + result[i+arr_x[k]][j+arr_y[k]]);
	                GLOB_MAX = max(max_val,GLOB_MAX);
	            }
	        }
	        result[i][j] = max_val;
	        
	    }
	   

	   //PRINT RESULT MATRIX 
	    // for(int i=0;i<n;i++){
	    //     for(int j=0;j<m ;j++)
	    //         cout << result[i][j] <<  " ";
	    //    cout << endl;
	    // }
	    
	    cout << GLOB_MAX << endl;
	        
	}
	return 0;
}