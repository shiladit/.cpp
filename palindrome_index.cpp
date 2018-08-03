#include <bits/stdc++.h>

using namespace std;

bool check_pali(string s){
    
    int upper = s.length()-1;
    int lower=0;
    
    // cout << upper << endl;
    
    while(lower <= upper){
        // cout << lower << "--" << upper << endl;
        if(s[lower] != s[upper])
            return false;
        
        lower++;
        upper--;
    }
    
    
    
    return true;
}

// Complete the palindromeIndex function below.
int palindromeIndex(string s) {
    
    
    
    bool flag = check_pali(s);
    
    if(flag == true){
        // cout << "-1" << endl;
        return -1;
    }
    
    
    for(int i=0;i<s.length();i++){
        string t =s ;    
        t.erase(i,1);
         // cout << t << "--" << i << endl;
        flag = check_pali(t);
        if(flag == true)
            return i;
    }
    
    return -1;
    
}

int main()
{
   

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s;
        getline(cin, s);

        int result = palindromeIndex(s);

        cout << result << "\n";
    }


    return 0;
}

