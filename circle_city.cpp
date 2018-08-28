#include <bits/stdc++.h>

using namespace std;

int main() {
    long t,r_square,points;
    cin >> t;
    
    while(t--){
        cin >> r_square >> points;
        int radius = ceil(sqrt(r_square));
        
        long count =0;
        
        for(int i=0;i<radius;i++) {
                float k = sqrt(r_square - (i*i));
                // cout << k << endl;
                if(k == floor(k))
                    count = count+4;                    
        }
            
        
        
        // cout << count << endl;
        
        if(count <= points)
            cout << "possible" << endl;
        else
            cout << "impossible" << endl;
    }
}