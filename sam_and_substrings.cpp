#include <bits/stdc++.h>

using namespace std;

// Complete the substrings function below.
long long int substrings(string s) {
    
    long f = 1;
    long long int sum = 0;
    for(long long int i=s.length()-1;i>=0;i--){
        sum = (sum + (s[i]-'0')*f*(i+1))% (1000000007);
        f = ((f*10)+1)% (1000000007);
    }

    return sum;
}

int main()
{

    string s;
    getline(cin, s);

    long long int result = substrings(s);

    cout << result << "\n";

    return 0;
}

