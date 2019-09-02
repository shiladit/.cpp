//shiladitya
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#define ll long long
#define f(i,a,b) for(ll i=a;i<b;i++)
#define mod (1000*1000*1000+7)
#define vi vector < int >
#define vb vector < bool >
#define vl vector < ll >
#define vvi vector < vector <int> >
#define vvc vector < vector <char> > 
#define pqueue priority_queue< int >
#define pdqueue priority_queue< int,vi ,greater< int > >

using namespace std;

int main() {
   vl arr;
   ll n, d;
   cin >> n >> d;

   f(i,0,n){
       ll x;
       cin >> x;
       arr.push_back(x);
   }

   vl aux(n,-100);

   f(i,0,n){
       ll new_index = (i-d);
       if(new_index < 0)
        new_index= new_index + n;

        aux[new_index]= arr[i];
   }

   f(i,0,aux.size())
        cout << aux[i] << " ";

    cout << endl;

}
