#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <string>
using namespace std;


int main() {
    
    map <string,int> dir;
    
    int q,no;
    string name;
    
    cin >> q;
    
    for(int i=0;i<q;i++){
        cin >> name >> no;
        dir.insert(pair <string, int> (name,no));
    }
    
//     for(map <string,int>::iterator it =dir.begin(); it !=dir.end(); it++)
//         cout << it->first << " " << it->second << endl;
    
    
    
    string s;
    
    while(std::getline(std::cin,s)) {
            
            map <string,int>::iterator it =dir.begin();
            it = dir.find(s);
          
           if(it != dir.end())
                cout << it->first << "=" << it->second << endl;
            else 
                cout << "Not found" << endl;
        
    }
    
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}