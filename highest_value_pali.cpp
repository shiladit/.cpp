//shiladitya
#include <bits/stdc++.h>
#define ll long long
#define f(i,a,b) for(ll i=a;i<b;i++)
#define pb push_back
#define mp make_pair
#define mod (1000*1000*1000+7)
#define vi vector <int>
#define vl vector <ll>
#define vb vector <bool>
#define pqueue priority_queue< int >
#define pdqueue priority_queue< int,vi ,greater< int > >

using namespace std;

int set_lindex(string s){
	if(s.length()%2 == 1)
		return s.length()/2;
	else
		return (s.length()/2)-1;
}

int set_rindex(string s){
		return s.length()/2;
}



int main() {

int n,k;
cin >> n >> k;

string s;
cin >> s;

vb visited(n,false);

int lindex = set_lindex(s);
int rindex = set_rindex(s);

while(rindex != n){

	if(s[lindex] > s[rindex]){
		s[rindex] = s[lindex];
		visited[rindex] = true;
		k--;
	}
	else if (s[lindex] < s[rindex]){
		s[lindex] = s[rindex];
		visited[lindex] = true;
		k--;
	}
	else
		;

	lindex--;
	rindex++;
}

if(k < 0)
	cout << "-1" << endl;
else if (k == 0)
	cout << s << endl;
else {
	int i=0;
	int j= n-1;
	
	while(i <= j){
		if(s[i] == s[j] && s[i] != '9' && k>=2 && visited[i] == false &&  visited[j] == false){
			s[i] = s[j] = '9';
			k = k -2;
		}
		else if(s[i] == s[j] && s[i] != '9' && k>=1 && (visited[i] == true | visited[j] == true)){
			s[i] = s[j] = '9';
			k = k-1;
		}
		else if( i == j && s[i] != '9' && k>0){
			s[i] = '9';
			k = k-1;
		}
		i++;
		j--;
	}
	cout << s << endl;
}
	
}