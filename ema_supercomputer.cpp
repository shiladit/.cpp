#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

int maxOne =0;
int maxTwo =0;
int max_area =0;

int check(vector <string> grid,int row,int col) {
    int u=row;
    int r=col;
    int l=col;
    int d=row;
    int count=0;
    
    while((u != -1) && (r != grid[0].size()) && (l != -1) && (d != grid.size())){
        if(grid[u][col] == 'G' && grid[row][r] == 'G' && grid[row][l] == 'G'&& grid[d][col] == 'G') {
            count=count+1;
            u--;
            r++;
            l--;
            d++;
            
        }
        else
            break;
    }

    if(count > 1)
        count = (count-1)*4 +1;

    if(maxOne < count){
                maxTwo = maxOne;
                maxOne =count;
    } 
    else if(maxTwo < count){
                maxTwo = count;
    }


    int area = maxOne*maxTwo;

    if((area>max_area) && (!overlap(grid)))
        return area;
    else
        return max_area;
}

// Complete the twoPluses function below.
int twoPluses(vector<string> grid,int n,int m) {
    
    // vector <int> arr(n*m,0);
    
    int area = 0;
    i
    

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j] == 'G'){
                area = check(grid,i,j);
            }
        }
    }
    
    return area;
}

int main()
{

    string nm_temp;
    getline(cin, nm_temp);

    vector<string> nm = split_string(nm_temp);

    int n = stoi(nm[0]);

    int m = stoi(nm[1]);

    vector<string> grid(n);

    for (int i = 0; i < n; i++) {
        string grid_item;
        getline(cin, grid_item);

        grid[i] = grid_item;
    }

    int result = twoPluses(grid,n,m);

    cout << result << endl;

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
