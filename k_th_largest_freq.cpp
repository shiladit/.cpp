#include <bits/stdc++.h>
using namespace std;

int main(){

    int t;
    cin >> t;

    while(t--){

    int n,k ;
    cin >> n >> k; 
    string s;
    cin >> s;

    int arr[26] = { 0 } ;

    for(int i=0;i<s.length();i++){
        arr[s[i]-'a']++;
    }

    map <int,char, greater<int> > umap;

    for(int i=0;i<26;i++){
        if(arr[i] != 0){
            char c= i + 97;

            if(!umap[arr[i]])
                umap[arr[i]] = c;
        }

    }

    map <int,char> :: iterator it;

    int count = 0;
    bool flag = false;
    for(it = umap.begin(); it !=umap.end(); it++){
        // cout << it->first << " -->" << it->second << endl;
        count++;
        if(count == k){
            cout << it->second << endl;
            flag = true;
            break;
        }
    }
    if(!flag)
        cout << "NONE" << endl;
    }
}