//shiladitya
#include <bits/stdc++.h>
#define ll long long
#define f(i,a,b) for(ll i=a;i<b;i++)
#define pb push_back
#define mp make_pair
#define mod (1000*1000*1000+7)
#define vi vector < int >
#define vl vector < ll >
#define pqueue priority_queue< int >
#define pdqueue priority_queue< int,vi ,greater< int > >

using namespace std;

int primes[30] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101,103,109};

ll calc_ascii(string s){
	ll sum =0;

	f(i,0,s.length()){
		sum = sum + (primes[s[i]-'a']*((int)s[i]));
	}

	return sum;
}

int main() {

	int n;
	cin >> n;

	while(n--){
		string s;
		cin >> s;

		map <ll,ll> map1;

		f(i,0,s.length()){
        	for (int len = 1; len <= s.length() - i; len++) {
            	string sub_str = s.substr(i, len);
            	ll sum = calc_ascii(sub_str);
            	cout << sub_str << " --> " << sum << endl;
        		
        		if(map1.find(sum) == map1.end())
        			map1[sum] = 0;
        		else{
        			map1[sum]++;
        		}
        	}
        }

        map <ll,ll> :: iterator it;

        // for(it= map1.begin();it !=map1.end();it++){
        // 	cout << it->first << " --> " << it->second << endl;
        // }

        ll total_comb = 0;

        for(it= map1.begin();it !=map1.end();it++){
        	if(it->second > 0)
        		total_comb += ((it->second)*(it->second+1))/2;
        }

        cout << total_comb << endl;



	}
	
}