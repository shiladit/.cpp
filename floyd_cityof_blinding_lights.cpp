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

int arr[500][500];

int main() {
	ll n,m;
	cin >> n >> m;

	ll u,v,r;

	f(i,0,n)
		f(j,0,n){
			if(i==j)
				arr[i][j] = 0;
			else
				arr[i][j] = 10000;
		}

	f(i,0,m){
		cin >> u >> v >> r;
		u = u-1;
		v = v-1;
		arr[u][v] = r;
	}

	 for (int k = 0; k < n; k++)  
    {  
        for (int i = 0; i < n; i++)  
        {   
            for (int j = 0; j < n; j++)  
            {  
                if (arr[i][k] + arr[k][j] < arr[i][j])  
                    arr[i][j] = arr[i][k] + arr[k][j];  
            }  
        }  
    }  

	ll q;
	cin >> q;

	while(q--){
		ll x,y;
		cin >> x >> y ;

		if(arr[x-1][y-1] != 10000)
			cout << arr[x-1][y-1] << endl;
		else
			cout << "-1" << endl;
	}

}

/* DEBUG

f(i,0,n){
			f(j,0,n)
				cout << arr[i][j] << " ";
			cout << endl;
		}

*/