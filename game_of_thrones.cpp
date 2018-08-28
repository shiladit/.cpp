#include <bits/stdc++.h>

using namespace std;

// Complete the gameOfThrones function below.
string gameOfThrones(string s) {
    
    map <char,long> umap;
    
    for(int i=0;i<s.length();i++){
        umap[s[i]]++;
    }
    
    map <char,long> :: iterator it;
    
  
    bool flag = false;
    
    for(it=umap.begin();it!=umap.end();it++){
        if(!flag && (it->second)%2 == 1)
            flag =true;
        else if(flag == true && (it->second)%2 == 1)
            return "NO";
    }
    
   return "YES";

}

int main()
{
    string s;
    cin >> s;

    cout << gameOfThrones(s) << endl;

    return 0;
}

