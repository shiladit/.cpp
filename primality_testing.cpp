#include <bits/stdc++.h>

using namespace std;

bool check_prime(long num){
    for(int i=3;i<=sqrt(num);i=i+2){
        if(num%i == 0)
            return false;
    }
    return true;
}

int main() {
    long t;
    cin >> t;
    
    while(t--){
        long num;
        cin >> num;
        
        if(num ==1){
            cout << "Not prime\n";
        }
        else if(num ==2){
            cout << "Prime\n";
        }
        else if(num % 2 ==0){
          cout << "Not prime\n";
        }  
        else{
            bool flag = check_prime(num);
            if(!flag)
                cout << "Not prime\n";
            else
                cout << "Prime\n";
        }
    }
}