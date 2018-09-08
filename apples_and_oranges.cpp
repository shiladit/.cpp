#include <bits/stdc++.h>

using namespace std;

int main() {
    long s,t;
    cin >> s >> t;
    long a,b;
    cin >> a >> b;
    
    long size1,size2,temp;
    cin >> size1 >> size2;
        
    long count = 0;
    for(int i=0;i<size1;i++){
        cin >> temp;
        temp = a + temp;
        if(temp >=s && temp <=t)
            count++;
    }
    
    cout << count << endl;

    count=0;
    for(int i=0;i<size2;i++){
        cin >> temp;
        temp = b + temp;
        if(temp >=s && temp <=t)
            count++;
    }
    
    cout << count << endl;
}