#include <bits/stdc++.h>
#include <stack> 

using namespace std;


int main() {
    int q;
    cin >> q;
    int val,type;
    int max_val = -INT_MAX; 
    stack <int> s1;
    stack <int> s2;
    
    
    while(q){
        cin >> type;
        if(type == 1){
            cin >> val;
            s1.push(val);
            
            if(s2.empty())
                s2.push(val);
            else{
            
            if(val > s2.top() )
                s2.push(val);
            else
                s2.push(s2.top());
            }
            
            
            
        }
        
        else if (type == 2){
            s1.pop();
            s2.pop();
        }
        else if(type == 3){
            
            cout << s2.top() << endl;     
        }         
        q--;       
    }
    return 0;
}

