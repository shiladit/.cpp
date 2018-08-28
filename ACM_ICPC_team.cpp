#include <bits/stdc++.h>

using namespace std;

int max_count =-INT_MAX ;
int number_of_values =0 ;
int set_count = 0;

int arr[500][500];


int main(){
    int n,m,temp;
    string s;
    cin >> n >> m;
    
    
    for(int i=0;i<n;i++){
        cin >> s;
        for(int j=0;j<m;j++){
            arr[i][j] = s[j]-48;
        }
    }
    
    for(int i=0;i<n;i++)
        for(int j=i+1;j<n;j++){
            if(i != j){
                set_count =0;
                for(int k=0;k<m;k++){
                    if(arr[i][k] == 1 || arr[j][k] ==1) 
                        set_count++;
                }
                
                if(set_count > max_count){
                    max_count = set_count;
                    number_of_values = 0;
                    
                }  

                if(set_count == max_count)
                    number_of_values++;
                    
            }
                
        }
        
    
    cout << max_count << endl;
    cout << number_of_values << endl;
    
}