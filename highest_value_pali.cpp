#include <bits/stdc++.h>

using namespace std;

long k1 =0 ;
string s;

vector <bool> check_pali(){
    long len= s.length();
    int i;
    int j;

    vector <bool> aux(len,false);
    
    for(i=0,j=len-1;i<=j;i++,j--){
        
        if(s[i] > s[j]){
            aux[j] = true;
            s[j] = s[i];
            k1++;
        }
        else if(s[i] < s[j]){
            aux[i] = true;
            s[i] = s[j];
            k1++;
        }
        else
            ;
    }
    
   return aux; 
            
}

int main() {
    long n,k;
    
   
    
    cin >> n >> k;
    cin >> s;

    int len = s.length();


    if(k >= (len)){
        for(int i=0;i<len;i++)
            s[i] = '9';

        cout << s << endl;
        return 0;
    }

    vector <bool> aux;
    
    aux = check_pali();

    // cout << s << endl;

    // for(int i=0;i<aux.size();i++)
    //     cout << aux[i] << " ";

    // cout << endl;

    int rem_k = k-k1; // Remaining value of k

    if(rem_k <0) {
        cout << "-1\n" ;
        return 0;
    }

    if(rem_k ==0){
        cout << s << endl;
        return 0;
    }



    int i = 0;
    int j= len-1;

    while((i<=j) && (rem_k >0)){
        if (aux[i] == true && aux[j] == false){
            s[i] = '9';
            s[j] = '9';
            rem_k = rem_k -1;
            i++;
            j--;
        }
        else if (aux[i] == false && aux[j] == true){
            s[i] = '9';
            s[j] = '9';
            rem_k = rem_k -1;
            i++;
            j--;
        }
        else if (aux[i] == false && aux[j] == false  && (rem_k > 1)){
            if(s[i] != '9'){
                s[i] = '9';
                rem_k = rem_k-1;
            }
            if(s[j] != '9'){
                s[j] = '9';
                rem_k = rem_k-1;
            }
        }
        else if( i ==j && rem_k ==1){
            if(s[i] != '9')
                s[i] = '9';
                i++;
                j--;   
        }
        else
            i++;
            j--;
    }
        
        cout << s << endl;
}   
          