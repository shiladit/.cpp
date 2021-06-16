#include <bits/stdc++.h>
using namespace std;

bool comp(pair <long,long> &a,pair <long,long> &b)
{
    if (a.first < b.first) 
        return true;
    else if(a.first == b.first)
        return a.second < b.second;
    else
        return false;
}

int main()
{
    long cust,order_no,prep_time;
    cin >> cust;
        
    vector <pair <long,long> > arr;
    
    for(long i=0;i<cust;i++){
         cin >> order_no >> prep_time;
         long sum = order_no+prep_time;
         arr.push_back(make_pair(sum,i+1));
    }
    
    vector <pair <long,long> > :: iterator it;
    sort(arr.begin(),arr.end(),comp);
    
    for(it=arr.begin();it != arr.end();it++){
        pair <long,long> p = *it;
        cout << p.second << " ";
    }

    cout << endl;
}
