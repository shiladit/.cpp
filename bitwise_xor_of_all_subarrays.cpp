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

void print(vi prefix_arr){
	for(int i=0;i<prefix_arr.size();i++)
		cout << prefix_arr[i] << " ";

	cout << endl;
}

int main() {

int n;
cin >> n;

vi arr(n);

f(i,0,n)
	cin >> arr[i];

vi prefix_arr(n);
prefix_arr[0] = arr[0];

f(i,1,n)
	prefix_arr[i] =  prefix_arr[i-1]^arr[i];

// print(prefix_arr);

ll sum =0;

f(i,0,n)
	f(j,0,n){
		if(i <= j){
			if(i == 0){
				sum = sum + prefix_arr[j];
			}
			else {
				sum = sum + (prefix_arr[j]^prefix_arr[i-1]);
			}

		}
		else
			;
	
	}

	cout << sum << endl;

}