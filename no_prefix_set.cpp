#include<bits/stdc++.h>
using namespace std;


int main() {
    long n;
    cin >> n;
    string s,p;
    map <string,long> m;
    map <string,long> :: iterator it;
    
    

    while(n--){
        cin >> s;

        if(m.find(s) != m.end()){
            cout << "BAD SET" << endl;
            cout << s << endl;
            return 0; 
        }

        m[s]=1;



        it= m.find(s);
        
        if(it !=m.begin()){
            it--;
            
            p = it->first;
            
            int len = min(s.length(),p.length());
            p = p.substr(0,len);
            
            if(s.find(p) == 0){
                cout << "BAD SET" << endl;
              
                cout << s << endl;
                return 0;
            }
            
        }
        
        it= m.find(s);
        
         if(++it !=m.end()){         
            p= it->first;

            int len = min(s.length(),p.length());
            p = p.substr(0,len);
                        
            if(s.find(p) == 0){
                cout << "BAD SET" << endl;
                cout << s << endl;
                return 0;
            }
             
        }
  
        }
        
    cout << "GOOD SET" << endl;
    return 0;
}


