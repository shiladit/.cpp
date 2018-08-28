#include <bits/stdc++.h>

using namespace std;

bool check_all(vector <int> arr){
    
    for(int i=0;i<26;i++)
        if(arr[i] == 0)
            return false;
    
    return true;
}


string pangrams(string s) {
    
    vector <int> arr(26,0); 
    
    for(int i=0;i<s.length();i++){
        if(arr[tolower(s[i])-97] == 0)
            arr[tolower(s[i])-97] = 1;
    }
    
    bool flag = check_all(arr);
    
    if(flag)
        return "pangram" ;
    else
        return "not pangram" ;

}

int main()
{

    string s;
    getline(cin, s);

    string result = pangrams(s);

    cout << result << "\n";  

    return 0;
}

