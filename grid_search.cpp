#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

bool check (int x,int y,vector<string> G,vector<string> P){
    
    int x_cord=x;
    int y_cord=y;
    int P_size = P.size() * P[0].size();
    // cout << P_size << endl;
    int count=0;
    for(int i=0;i<P.size();i++){
        for(int j=0;j<P[0].size();j++){
            if(G[x][y] != P[i][j])
                break;
            else{
                y++;
                count++;
            }
        }
        x++;
        if(count == P_size)
        return true;
    
        if(x >= G.size())
        	return false;

        y=y_cord;
    }

    // cout << "Count: " << count << endl;
    
    if(count == P_size)
        return true;
    else 
        return false;
}

// Complete the gridSearch function below.
void gridSearch(vector<string> G, vector<string> P) {
    bool flag= false;
    
    for(int i=0;i<G.size();i++){
        for(int j=0;j<G[0].size();j++){
            // cout << G[i][j] << " ";
            if(G[i][j] == P[0][0]){
                flag = check(i,j,G,P);
                if(flag == true){
                    cout << "YES" << endl;
                    return;
                
                }
                
            }
        }       // cout << endl;
	}

if(!flag)
	cout << "NO" << endl;

}

int main()
{

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string RC_temp;
        getline(cin, RC_temp);

        vector<string> RC = split_string(RC_temp);

        int R = stoi(RC[0]);

        int C = stoi(RC[1]);

        vector<string> G(R);

        for (int i = 0; i < R; i++) {
            string G_item;
            getline(cin, G_item);

            G[i] = G_item;
        }

        string rc_temp;
        getline(cin, rc_temp);

        vector<string> rc = split_string(rc_temp);

        int r = stoi(rc[0]);

        int c = stoi(rc[1]);

        vector<string> P(r);

        for (int i = 0; i < r; i++) {
            string P_item;
            getline(cin, P_item);

            P[i] = P_item;
        }

        gridSearch(G, P);

        
        
    }

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
