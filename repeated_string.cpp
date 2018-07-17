#include <bits/stdc++.h>

using namespace std;

// Complete the repeatedString function below.
void repeatedString(string s, long n) {
    long count=0;
    

    for(int i=0;i<s.length() ;i++){
                if(s[i] == 'a')
                    count++;
            }

    long count_first = (n/s.length())*count;
    int rest = n%s.length();
       
    for(int i=0;i<rest;i++){
        if(s[i] == 'a')
             count_first++;
              
        }
    
    cout << count_first << endl;
   
}

int main()
{

    string s;
    getline(cin, s);

    long n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    repeatedString(s, n);


    return 0;
}

