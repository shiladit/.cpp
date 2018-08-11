#include <bits/stdc++.h>

using namespace std;

int minimumTime(vector <int> x) {
    
    if(x.size() == 1)
        return 0;
    
    sort(x.begin(),x.end());
    
    return abs(x[0]-x[x.size()-1]);
    //  Return the minimum time needed to visit all the houses.         
}

int main() {
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        int n;
        cin >> n;
        vector<int> x(n);
        for(int x_i = 0; x_i < n; x_i++){
        	cin >> x[x_i];
        }
        int result = minimumTime(x);
        cout << result << endl;
    }
    return 0;
}