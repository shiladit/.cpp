#include<bits/stdc++.h>
using namespace std;
int strstr(string ,string);
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string a;
        string b;
        cin>>a;
        cin>>b;
        cout<<strstr(a,b)<<endl;
    }
}


/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/* The function should return position where the target string 
   matches the string str
Your are required to complete this method */
int strstr(string s, string x)
{   
     bool flag = true;
     int start = -1;


     for(int i=0;i<s.length();i++){
         if(x[0] == s[i]){
             int j=0;
             
             // cout << i << endl;
             while(j != x.length()){
                 if(x[j] != s[i+j]){
                    flag = false;
                    break;
                    }
                j++;    
             }

             if(j==x.length()){
                start = i;
                flag = true;
                return start;
            }
             
             
         }
         
     }
       return -1;

    
}