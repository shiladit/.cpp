#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    
    vector<int> start,end;
    for(int i=0;i<n;i++)
    {
        int a,b;
        cin>>a>>b;
        
        start.push_back(a);
        end.push_back(b);
    }
    
    sort(start.begin(),start.end());
    sort(end.begin(),end.end());
    
    int strength=0;
    for(int i=0;i<m;i++)
    {
        int c,d;
        cin>>c>>d;
        
        vector<int>::iterator itr1,itr2;
        itr1 = upper_bound(start.begin(),start.end(),d);
        itr2 = lower_bound(end.begin(),end.end(),c);
        
        int count=0;
        if(itr1!=start.end())
        {
            count+= distance(itr1,start.end());
        }
        if(itr2!=end.begin())
        {
            count+= distance(end.begin(),itr2);
        }
        strength+=n-count;
    }
    
    cout<<strength<<endl;
    
    return 0;
}