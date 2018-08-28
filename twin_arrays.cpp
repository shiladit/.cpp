#include <bits/stdc++.h>

using namespace std;

void print_map(map <long,long> umap){
    map <long,long> :: iterator it;

    for(it= umap.begin();it != umap.end();it++){
        cout << it->first << " -- " << it->second << endl;
    }
}

void print_multiset(multiset <pair <int,int> > s){
    multiset <pair <int,int> > :: iterator it;

    it = s.begin();

    while(it != s.end()){
        cout << it->first << " -- " << it->second << endl;
        it++;
    }
}

int main() {
    
    long size,temp;
    
    cin >> size;
    
    
    multiset <pair <int,int> > s1;
    multiset <pair <int,int> > s2;

    for(int i=0;i<size;i++){
        cin >> temp;
        s1.insert(make_pair(temp,i));
    }


    for(int i=0;i<size;i++){
        cin >> temp;
        s2.insert(make_pair(temp,i));
    }

    // print_multiset(s1);

    multiset <pair <int,int> > :: iterator it1;
    multiset <pair <int,int> > :: iterator it2;

    it1 = s1.begin();
    it2 = s2.begin();

    if(it1->second != it2->second){
        cout << it1->first + it2->first ;
        return 0;
    }

    if( (++it1)->first > (++it2)->first){
        it2--;
        cout << it1->first + it2->first ;
        return 0;

    }

    if( (++it1)->first < (++it2)->first){
        it1--;
        cout << it1->first + it2->first ;
        return 0;

    }


        
    
    
    return 0;
    
}
    