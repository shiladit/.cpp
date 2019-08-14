//shiladitya
#include <bits/stdc++.h>
#define ll long long
#define f(i,a,b) for(ll i=a;i<b;i++)
#define mod (1000*1000*1000+7)
#define vi vector < int >
#define vl vector < ll >
#define pqueue priority_queue< int >
#define pdqueue priority_queue< int,vi ,greater< int > >

using namespace std;



int main() {

int t;
cin >> t;

while(t--){

int n;
cin >> n;

ll arr[100][100];
vector <ll> capacity(100,0);

f(i,0,n){
	ll box_size = 0;
	f(j,0,n){
		ll val;
		cin >> val;
		arr[i][j] = val;
		box_size += val;
	}

	// cout << box_size << endl;
	capacity[i] = box_size;
}



vector <ll> num_balls(100,0);

f(i,0,n){
	ll balls =0;
	f(j,0,n){
		balls += arr[j][i];
	}
	num_balls[i] = balls;
}



bool flag = false;

sort(capacity.begin(),capacity.begin()+n);
sort(num_balls.begin(),num_balls.begin()+n);

f(z,0,n){

	// cout << capacity[z] << " -- " << num_balls[z] << endl; 
	if(capacity[z] != num_balls[z]){
		flag = true;
		break;
	}
	else
		;
}

if(flag)
	cout << "Impossible\n";
else
	cout << "Possible\n";


	
} 
	
}



/*DEBUG

for(int i=0;i<n;i++)
	for(int j=0;j<n;j++)
		cout << << endl;

cout << << << endl;

*/

