//shiladitya
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
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

int a;
cin >> a;

vi arr(a);

f(i,0,a)
	cin >> arr[i];

sort(arr.begin(),arr.end());

int i=0;
int max_len = 1;

while(i<a){
	int j = i+1;
	int len = 1;

	while(abs(arr[i]-arr[j]) <= 1){
		j++;
		len++;
	}

	if(len > max_len)
		max_len = len;

	i++;
}

cout << max_len << endl;
	
}