#include <bits/stdc++.h>

using namespace std;

int main(){
    long n;
    cin >> n;
    
    stack <pair <long,long> > stk;
    long h;
    long count = 0;
    
    stk.push(make_pair(INT_MAX,1));
    
    for(int i=0;i<n;i++){
        cin >> h;
        
        while(!stk.empty() && (h > stk.top().first))
            stk.pop();
        
        if((h < stk.top().first) && !stk.empty())
            stk.push(make_pair(h,1));
        else if(h==stk.top().first)
        {
                count = count + stk.top().second;
                stk.top().second++;
        }
        else 
            ;
        
        
    }
    
    cout << 2*count << endl;
}