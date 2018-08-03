#include <iostream>
#include <vector>

using namespace std;




int find_conn(vector <vector<int> > matrix,int r,int c){
    
    matrix[r][c] = 2;
    cout << r << " -- " << c << endl;
    // int count=1;
    int count=1;

    for(int i=r-1;i<=r+1;i++){
        for(int j=c-1;j<=c+1;j++){
            bool flag = (i>=0 && i<matrix.size()) && (j>=0 && j<matrix[i].size());
            if(flag && !((matrix[i][j] == 2) || (matrix[i][j] == 0 ))){
                // cout << i << " -- " << j << endl;
                count = 1 + find_conn(matrix,i,j);
            }
        }
    }
    
    
    
    return count;
}

// Complete the connectedCell function below.
int connectedCell(vector <vector<int> > matrix) {
    int max = -1;
    
    
    for(int i=0;i<matrix.size();i++)
        for(int j=0;j<matrix[i].size();j++) {
            if(matrix[i][j] == 1){
                int sum = find_conn(matrix,i,j);
                cout << "BUM\n";
                if(sum > max)
                    max = sum;
                
            }
        }
    
    
    return max;
    
    
}

int main()
{
    
    int n,m;
    int temp;
    
    
    cin >> n;
    
    cin >> m;

    vector<vector<int> > matrix(n); 
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> temp;
            matrix[i].push_back(temp);
        }
        
    }

    


    
    int result = connectedCell(matrix);

    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < m; j++) {
    //         cout << matrix[i][j] << " ";
    //     }
    //     cout << endl;
        
    // }
    
    cout << result << endl;
    
    return 0;
}

