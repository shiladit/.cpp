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
	int n;
	cin >> n;
	vector <int> arr;

	for(int i=0;i<n;i++){
		int x;
		cin >> x;
		arr.push_back(x);
	}

	priority_queue <pair <int,int> > q;

	int k;
	cin >> k;

	int max_val = -INT_MAX;

	for(int i=0;i<k;i++){
		q.push(make_pair(arr[i],i));
		if(arr[i] > max_val)
			max_val = arr[i];
	}

	int j=k;

	while(j != n){
		if(arr[j] > q.top().first){
			cout << arr[j] << " ";
			q.push(arr[j],j);
			
		}
		else{
			while((q.top().second < (j-k)) || q.top().first < arr[j]){
				q.pop();
			}
			q.push(arr[j],j);
		}
	}



}