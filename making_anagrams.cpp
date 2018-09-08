#include <bits/stdc++.h>

using namespace std;

int main(){
    string s1,s2;
    
    cin >> s1; cin >> s2;
    
    int arr1[26] = {0};
    int arr2[26] = {0};
    
    for(int i=0;i<s1.length();i++){
        int index = s1[i]-'a';
        arr1[index]++;
    }
    
    for(int i=0;i<s2.length();i++){
        int index = s2[i]-'a';
        arr2[index]++;
    }
    
    int diff =0;
    
    for(int i=0;i<s1.length();i++){
        int count1= arr1[s1[i]-'a'];
        int count2= arr2[s1[i]-'a'];
        diff = diff + abs(count1-count2);
        arr1[s1[i]-'a'] = 0;
        arr2[s1[i]-'a'] = 0;
        
    }
    
    for(int i=0;i<26;i++){
        diff = diff + arr2[i];
    }
    
    cout << diff << endl;
        
    
}