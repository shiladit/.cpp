#include <bits/stdc++.h>
#define ll long long
#define f(i,a,b) for(ll i=a;i<b;i++)

using namespace std;


int main() {

	int n;
	cin >> n;

	while(n--){

    string s;
    cin >> s;
    string pat = "hackerrank";

    int len = 10;

    int count=0;
    int j=0;

    f(i,0,s.length()){
        if(s[i] == pat[j]){
            count++;
            j++;
        }
    }

    if(count == len)
    	cout << "YES" << endl;
    else
    	cout << "NO" << endl;
	}
}