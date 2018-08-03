#include <bits/stdc++.h>

using namespace std;

// Complete the isBalanced function below.
bool isBalanced(string s) {
    stack <char> s1;
    int len = s.length();
    
    
    
    for(int i=0;i<len;i++){
        if((s[i] == '(') || (s[i] == '{') || (s[i] == '[')){
            char temp = s[i];
            s1.push(temp);
        }
        else if(((s[i] == ')') || (s[i] == '}') || (s[i] == ']')) && (s1.empty())){
            return false;
        }
        else if(s[i] == ')' && s1.top() == '(') {
                s1.pop();
            
        }
        else if(s[i] == '}' && s1.top() == '{') {
                s1.pop();
            
        }
        else if(s[i] == ']' && s1.top() == '[') {
                s1.pop();
            
        }
        else 
            return false;
        
    }
    
    if(s1.empty())
        return true;
    else
        return false;


}

int main()
{

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string s;
        getline(cin, s);

        bool flag = isBalanced(s);
    
        if(flag == true)
            cout << "YES\n";
        else
            cout << "NO\n";
        
    }


    return 0;
}

