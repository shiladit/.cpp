#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {

    int n,q;

    cin >> n >> q;
    int lower,upper,val;

    vector <long> arr(n+1,0);


    for(int i=0;i<q;i++){
        cin >> lower >> upper >> val;
        
        arr[lower] = arr[lower] + val;

        if((upper+1) <= n)
            arr[upper+1] = arr[upper+1] - val;

        // for(int i=0;i<n+1;i++)
        //     cout << arr[i] << " ";
        // cout << endl;

    }

    long max =0;
    long x=0;

   for(int i=1;i<=n;i++)
    {
       x=x+arr[i];
       if(x>max) 
        max=x;

    }

    cout <<max << endl;



}