#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    cin >> s;
    
    vector <char> arr;
    
    for(int i=1;i<s.length();i++){

        if(s[i] == s[i-1]){
            s = s.substr(0,i-1) + s.substr(i+1);
            i=0;
        }
    }
    
    if(s.length() == 0)
        cout << "EMPTY STRING"<< endl;
    else
    {
        for(int i=0;i<s.length();i++)
            cout << s[i] ;
    }
}