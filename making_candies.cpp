//shiladitya
#include <bits/stdc++.h>
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
	ll machines;
	ll workers;
	ll cost;
	ll total_candies;

	cin >> machines >> workers >> cost >> total_candies;

	ll candies_acc_so_far = 0;
	ll step = 0;
	

	while(candies_acc_so_far < total_candies){

		if(candies_acc_so_far + (machines*workers) >= total_candies){
			candies_acc_so_far += machines*workers;
		}

		else if(candies_acc_so_far < cost){
			candies_acc_so_far += machines*workers;
			
		}
		else{
			ll units = candies_acc_so_far/cost;
			candies_acc_so_far = candies_acc_so_far - (units*cost);

			cout << units << " -- " << candies_acc_so_far << " -- " << step << endl;

			ll res1 = units/2;
			ll res2 = units-res1;

			if((machines+res1)*(workers+res2) > (machines+res2)*(workers+res1)){
				candies_acc_so_far += (machines+res1)*(workers+res2);
				machines = machines + res1;
				workers = workers + res2;
			}
			else{
				candies_acc_so_far += (machines+res2)*(workers+res1);
				machines = machines + res2;
				workers = workers + res1;

			}

		}
		++step;

		// cout << candies_acc_so_far << " -- " << step << endl;
		
	}

	cout << step ;

}
