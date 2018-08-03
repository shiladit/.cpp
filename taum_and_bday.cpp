#include <bits/stdc++.h>

using namespace std;


void taumBday(long long b, long long w, long long bc, long long wc, long long z) {
    long long sum =0;
    
    if(bc==wc){
        sum = (b*bc)+(w*wc);
        cout << sum ;
    }
    if(bc < wc){
        if((bc+z) ==wc){
            sum = (b*bc)+(w*wc);
            cout << sum;
        }
        if((bc+z)<wc){
            sum = (bc*b) + (bc+z)*w;
            cout << sum;
        }
        if((bc+z)>wc){
            sum = (b*bc)+(w*wc);
            cout << sum;
        }     
    }
    if(bc > wc){
        if((wc+z) ==bc){
            sum = (b*bc)+(w*wc);
            cout << sum;
        }
        if((wc+z)> bc){
            sum = (bc*b) + (wc*w);
            cout << sum;
        }
        if((wc+z)<bc){
            sum = (wc+z)*b+(w*wc);
            cout << sum;
        }     
    }

    cout << endl;

}

int main()
{
  

    int t;
    cin >> t;
    
    for (int t_itr = 0; t_itr < t; t_itr++) {
        
        long long b,w;
        long long bc,wc,z;

        cin >> b >> w;
        cin >> bc >> wc >> z;

        taumBday(b, w, bc, wc, z);

        
    }

    return 0;
}



