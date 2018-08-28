#include <iostream>
#include <string>


using namespace std;

int n,m;
char matrix[100][100];
int path[100][100];
int flag =0;
int paths = 0;


bool valid(int x,int y){
    
    if(x >=0 && y >=0 && x < n && y < m)
        return true;
    else
        return false;
}

int dfs(int x,int y){
    if(matrix[x][y] == '*'){
        path[x][y] = 200;
        flag =1;
        return 1;
    }
    
    
    if(matrix[x][y] == 'X'){
        return 0;
    }
    
    matrix[x][y] = '0';
    path[x][y] = 1;
    
    
    
    //UP
    if(valid(x-1,y) == true && matrix[x-1][y] != '0' && !flag){
        dfs(x-1,y);
    }
    
    //DOWN
    if(valid(x+1,y) == true && matrix[x+1][y] != '0' && !flag)
        dfs(x+1,y);
    
    
    //LEFT
    if(valid(x,y-1) == true && matrix[x][y-1] != '0' && !flag)
        dfs(x,y-1);
    
    //RIGHT
    if(valid(x,y+1) == true && matrix[x][y+1] != '0' && !flag)
        dfs(x,y+1);
    
    
    return 0;
}

vector<string> split_string(string);

// Complete the countLuck function below.
void countLuck() {
    
    int start_x= -1;
    int start_y= -1;
    
    
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            if(matrix[i][j] == 'M'){
                start_x = i;
                start_y = j;
                break;
            }
    
   // cout << start_x << " -- " << start_y << endl;
    
    dfs(start_x,start_y);
    
    
}

int main()
{
    
    
    int t;
    cin >> t;
    
    
    while(t--){
        
        string matrix_item;

        cin >> n >> m ;

        //Initializing path matrix
        for(int i=0;i<n;i++)
           for(int j=0;j<m;j++)
               path[i][j] = 0;
       

        for(int i=0;i<n;i++)
           for(int j=0;j<m;j++)
               path[i][j] =0;
        
        paths =0 ;

    
        
        for (int i = 0; i < n; i++) {
            cin >> matrix_item;
            for(int j=0;j<m;j++)
                matrix[i][j] = matrix_item[j];
        }

        cout << "Printing matrix\n";

       for(int i=0;i<n;i++){
           for(int j=0;j<m;j++){
               cout << matrix[i][j] << " ";
           }
       cout << endl;
       }
        
        
        int k;
        cin >> k;
        
        countLuck();
        
        
        if(flag ==1)
            cout << "Found" << endl;
        else
            cout << "Not Found" << endl;
        
       cout << "Printing path matrix\n";

       for(int i=0;i<n;i++){
           for(int j=0;j<m;j++){
               cout << path[i][j] << " ";
           }
       cout << endl;
       }


    }
    
    
    return 0;
}
