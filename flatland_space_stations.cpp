//shiladitya
#include <bits/stdc++.h>

using namespace std;

int main() {
    long n,m;
    cin >> n >> m;

    set <long> set1;

    for(int i=0;i<m;i++){
        long x;
        cin >> x;
        set1.insert(x);
    }

    set <long> :: iterator low,up;

    long max_val = -INT_MAX;

    for(int i=0;i<n;i++){
        long diff  = 0;

        if(set1.find(i) != set1.end())
            diff = 0;
        else{
            low=set1.lower_bound(i);
            up=set1.upper_bound(i);

            if(low != set1.begin())
                low--;

            if(abs(*low-i) < abs(*up-i))
                diff = abs(*low-i);
            else
                diff = abs(*up-i);
        }

        if(diff > max_val)
            max_val = diff;

        // cout << "City: " << i << " has nearest space station in " << diff << " Km\n"; 
    }
    cout << max_val << endl;
}