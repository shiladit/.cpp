//shiladitya
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <math.h>
#include <iomanip>
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

int main(){

long double t;
cin >> t;

long double ceiling = (log2((t/3)+1));
ceiling = ceil(ceiling);

ll base = ceiling - 1;
ceiling = (pow(2,ceiling)-1)*3;
base = (pow(2,base)-1)*3;

cout << fixed << (long long)(ceiling -t)+1 << endl;

}
