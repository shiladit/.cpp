#include <iostream>
using namespace std;

int main(){
    int t;
    cin >> t;

    while(t--){
        int a,b,c;

        cin >> a >> b >> c;
        int choc =  a/b; 
        int wrap = choc; 

        while(wrap >= c){
            choc += wrap/c;
            wrap = (wrap/c) + (wrap%c);
        }
        
        cout << choc << endl;
    }
}