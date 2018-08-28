#include <bits/stdc++.h>

using namespace std;

int main() {
    
    long t,n;
    cin >> t;
    
    while(t--) {
        cin >> n;
        
        bool turn =true; //Spring
        long height =1;
        
        while(n--){

            if(turn) {
                height = height*2;
                turn = !turn;
            }
            else {
                height = height+1;
                turn = !turn;
            }
        }

        cout << height << endl;
    }
}