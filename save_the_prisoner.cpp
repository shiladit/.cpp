#include <bits/stdc++.h>

using namespace std;


// Complete the saveThePrisoner function below.
void saveThePrisoner(long n, long m, long s) {

   long temp;

   if((m+s-1)%n ==0)
        temp = n;
   else
        temp = (m+s-1)%n;

    
    cout << temp << endl;

}

int main()
{
   

    int t;
    cin >> t;
    

    for (long t_itr = 0; t_itr < t; t_itr++) {
        long n,m,s;
        cin >> n >> m >> s;

        saveThePrisoner(n, m, s);
    }

    return 0;
}




