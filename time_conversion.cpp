#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the timeConversion function below.
 */
void timeConversion(string s) {
    int a = 0;
    int b = 0;
    if(s[8] == 'P'){
        a=1;
        if(s[0] == '1' && s[1] == '2' )
            b=s[1]-48;
        else
            b= s[1] -46;
    }
    else {

        if(s[0] == '1' && s[1] == '2'){
            a=0;
            b=0;
        }
        else
            b=s[1]-48;
        
    }
    // cout << a << " "  << b << endl;
    cout << a << b << s[2] << s[3] << s[4] << s[5] << s[6] << s[7] << endl; 
     

}

int main()
{
   

    string s;
    getline(cin, s);

    timeConversion(s);

    return 0;
}

