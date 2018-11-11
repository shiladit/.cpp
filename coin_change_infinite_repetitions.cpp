#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

void print_vec(vector <vector <int> > arr){
    
    for(int i=0;i<arr.size();i++){
        for(int j=0;j<arr[i].size();j++)
            cout << arr[i][j] << " ";
    
        cout << endl;
    }
}

void getWays(long n, vector<long> c) {
    
    int m = c.size();
    sort(c.begin(),c.end());
    
    vector <vector<long> > dp(m+1,vector <long> (n+1));
    
    for(int i=0;i<n+1;i++)
        dp[0][i] = 0;
    
    for(int i=0;i<m+1;i++)
        dp[i][0] = 1;
    
    for(int i=1;i<dp.size();i++)
        for(int j=1;j<dp[i].size();j++){
            if(c[i-1] <= j)
                dp[i][j] = dp[i][j-c[i-1]]+dp[i-1][j];
            else
                dp[i][j] = dp[i-1][j];
        }
    
    // print_vec(dp);
    
    cout << dp[m][n] << endl;
    
}

int main()
{
    string nm_temp;
    getline(cin, nm_temp);

    vector<string> nm = split_string(nm_temp);

    int n = stoi(nm[0]);

    int m = stoi(nm[1]);

    string c_temp_temp;
    getline(cin, c_temp_temp);

    vector<string> c_temp = split_string(c_temp_temp);

    vector<long> c(m);

    for (int i = 0; i < m; i++) {
        long c_item = stol(c_temp[i]);

        c[i] = c_item;
    }

    getWays(n, c);


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

