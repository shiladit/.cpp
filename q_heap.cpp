#include <bits/stdc++.h>

using namespace std;


int main() {
    
    long q;
    set <long> s;
    cin >> q;
    long o , val;
    
    
    
    while(q) {
        cin >> o ;
           
        if( o == 1){
            cin >> val;
            s.insert(val);    
        }
        
        else if(o == 2){
            cin >> val;
            if(s.find(val) != s.end())
                s.erase(s.find(val));
               
        }
        
        else  
            cout << *s.begin() << endl;
        
        
        q--;
    }
    
    return 0;
}

