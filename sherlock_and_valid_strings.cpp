#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    cin >> s;
    
    int arr[26] = {0};
    
    for(int i=0;i<s.length();i++){
        cout << s[i]-'a';
    }
    
    // for(int i=0;i<26;i++)
    //     cout << arr[i] << " ";
    
   set <int> s1; 
    
   for(int i=0;i<26;i++){
       if(arr[i] != 0)
           s1.insert(arr[i]);
   }
    
    set <int> ::iterator it;
    
    for(it = s1.begin();it != s1.end() ; it++)
        cout << *it << " ";
    
    cout << endl;
    
    if(s1.size()>2)
        cout << "NO" << endl;
    else
        cout << "YES" << endl;
    
   
    
   
}