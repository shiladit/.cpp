#include <bits/stdc++.h>

using namespace std;

int main() {
    
    long q;
    long a,b;
    cin >> q;
    while(q) {
        cin >> a >> b;
        long least1 = sqrt(a);
        // cout << least1 << endl;
        long least2 = sqrt(b);
        // cout << least2 << endl;
        long count = 0;
        
        while(least1 != least2+1){
            long temp = least1*least1;
            if(temp >= a && temp <=b){
                count++;
            }
            least1++;
        }
        
        cout << count << endl;
        
        q--;
    }
    
}

