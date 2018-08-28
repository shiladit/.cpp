#include <bits/stdc++.h>

using namespace std;

bool check_seq(vector <string> grid){
    for(int i=0;i<grid.size();i++){
        for(int j=0;j<grid[i].size()-1;j++){
             if(grid[j+1][i]<grid[j][i])
                 return false;
        }
    }
    
    return true;
}


string gridChallenge(vector<string> grid) {
    
    for(int i=0;i<grid.size();i++)
        sort(grid[i].begin(),grid[i].end());
        
    
    bool flag = check_seq(grid);
    
    if(flag)
        return "YES";
    else
        return "NO";
}

int main()
{
    int t;
    cin >> t;
   
    for (int t_itr = 0; t_itr < t; t_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        vector<string> grid(n);

        for (int i = 0; i < n; i++) {
            string grid_item;
            getline(cin, grid_item);

            grid[i] = grid_item;
        }

        string result = gridChallenge(grid);

        cout << result << "\n";
    }

    return 0;
}

