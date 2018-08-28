#include <bits/stdc++.h>

using namespace std;

int main() {
    string s1,s2;
    
    cin >> s1;
    cin >> s2;
    
    long m = s1.length();
    long n = s2.length();
    
    
    
    vector < vector<int> > arr(m+1,vector<int>(n+1));
    
    for(int i=0;i<m+1;i++)
        for(int j=0;j<n+1;j++)
            arr[i][j] = 0;
    

    
    for(int i=1;i<m+1;i++)
        for(int j=1;j<n+1;j++){
            if(s1[i-1] == s2[j-1])
                arr[i][j] = 1+arr[i-1][j-1];
            else 
                arr[i][j] = max(arr[i-1][j],arr[i][j-1]);
        }
    
//     for(int i=0;i<m+1;i++){
//         for(int j=0;j<n+1;j++){
//             cout << arr[i][j] << " ";
//         }
//     cout << endl;
//     }
    
    cout << arr[m][n] << endl ;
    
}