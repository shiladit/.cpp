#include<bits/stdc++.h>

using namespace std;

void print(map <long,long> umap){
    map <long,long> :: iterator it;

    for(it=umap.begin();it != umap.end(); it++){
        cout << it->first << " -> " << it->second << endl;
    }
}


int main() {
    long q;
    cin >> q;
    long m,n;
    
   
    map <long,long> umap;
    map <long,long> freq_map;
    map <long,long> :: iterator tt;

    int count=0;
    
    
    while(q) {
        cin >> m >> n;
        
        if(m == 1){
           
            if (umap.find(n) == umap.end()){
                umap[n] =1 ;
                if(freq_map[1] == 0)
                    freq_map[1] = 1;
                else
                    freq_map[1]++;
            }

            else {
                long old_val = umap[n];
                
                if(freq_map[old_val] > 0)
                    freq_map[old_val]--;

                long val = ++umap[n];
                freq_map[val]++;
            }
        }
        else if(m == 2){
            if(umap.find(n) != umap.end()){
                long old_val = umap[n];
                
                if(freq_map[old_val] > 0)
                    freq_map[old_val]--;
                
                if(umap[n] > 0)
                    umap[n]--;
            }
    
        }
        else if(m == 3){

            if(freq_map[n] > 0)
                cout << "1" << endl;
            else
                cout << "0" << endl;
             
                
        }
        else 
            ;
        
        cout << "\n--------UMAP----------------\n" ;
        print(umap);
        cout << "\n----------FREQ MAP--------------\n" ;
        print(freq_map);
        cout << "\n----------END OF LOOP " << count << " --------------\n" ;

        count++;
        
        q--;
    }
}