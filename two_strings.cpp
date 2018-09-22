#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    
    while(t--){
        string s1,s2;
        cin >> s1;
        cin >> s2;
        
        set <char> s;
        
        for(int i=0;i<s1.length();i++){
            s.insert(s1[i]);
        }
        
        bool flag = true;
        
        for(int i=0;i<s2.length();i++){
            if(s.find(s2[i]) != s.end()){
                flag = false;
                break;
            }
        }
        
        if(!flag)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}