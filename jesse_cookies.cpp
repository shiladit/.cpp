#include <bits/stdc++.h>

using namespace std;

int main() {
    
    long n,k,temp;
    cin >> n >> k ;
    
    priority_queue <long, vector<long>, greater<long> > p;
    long count=0;
    
    for(long i=0;i<n;i++){
        cin >> temp;
        
        p.push(temp);
    }

    // cout << p.top() << endl;

    while(p.size() != 1 && p.top() < k ){
        int least = p.top();
        p.pop();
        int lesser = p.top();
        p.pop();

        int new_s = 1*least + 2*lesser;
        p.push(new_s);

        count++;


    }

    if(p.size() ==1 && p.top() < k)
        cout << "-1" << endl;
    else
        cout << count << endl;
    


}