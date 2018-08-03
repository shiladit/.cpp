#include<bits/stdc++.h>

using namespace std;

/* TLE..  to remove you need to do binary search on the days.. set lower_limit of days to 0 and upper_limit of days as 10^14.. 
Check the middle value of it.. calculate work done on that day, if less move to left side of the search range , else move to right
Keep doing this untill you get the desired value */

int main() {
    long n,goal,temp;
    
    set <long> s;
    map <long,long> umap;
    
    cin >> n >> goal;
    
    for(int i=0;i<n;i++){
        cin >> temp;
        s.insert(temp);
        
        if(umap.find(temp) == umap.end())
            umap[temp] =1 ;
        else
            umap[temp]++;
    }
    
    // print_map(umap);
    // print_set(s);
    
    long count=0;
    
    set <long> :: iterator it;
    
    long sum =0;
    long day = *s.begin();
    
    while(sum < goal){
       
        for(it = s.begin() ; it != s.end() && sum < goal ; it++){
            if(day%*it == 0)
                sum = sum + umap[*it];
        }
        
        cout << "Day: " << day << " Sum: " << sum << endl;
    }
        cout << day-1 << endl;
    }