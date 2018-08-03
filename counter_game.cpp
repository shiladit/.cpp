#include<bits/stdc++.h>

using namespace std;

int main() {
    int T;
    long num;
    cin >> T;
    while(T) {
        cin >> num;
        int turn = 1 ; // Louise
        
        while((num != 1) && (num != 0 )){
            
            if(ceil(log2(num)) == floor(log2(num))){
                num = num>>1;
                turn = !turn;
            }
            else {
                long temp =1;
                while(temp <= num)
                    temp = temp<<1;
                
                temp = temp>>1;
                num = num-temp;
                
                turn = !turn;
            }
            // cout << num << "--" << turn << endl;
                
        }
         if(turn == 0)
                cout << "Louise\n";
            else
                cout << "Richard\n";
                
            
        
        
        T--;
    }
}