#include <bits/stdc++.h>

using namespace std;

// Complete the appendAndDelete function below.
void appendAndDelete(string s, string t, int k) {
    
    int len1 = s.length();
    int len2 = t.length();
    int i=0;
    // int j=0;
    
    if(len1-len2 > k){
        cout << "No\n";
        return;
    }
    else if(len1+len2 <= k) {
        cout << "Yes\n";
        return;
    }
    
    else {
        while( s[i] == t[i]){
            i++;
        }
        int rest_length = (len1+len2-2*i);
        // cout << rest_length << endl;
        if((rest_length <=k && rest_length%2 == 0 && k%2 ==0) || (rest_length <=k && rest_length%2 == 1 && k%2 ==1))
            cout << "Yes\n";
        else
            cout << "No\n";
                       
        }

}

int main()
{
   

    string s;
    getline(cin, s);

    string t;
    getline(cin, t);

    int k;
    cin >> k;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    appendAndDelete(s, t, k);


    return 0;
}


