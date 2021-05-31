//shiladitya
#include <iostream>
#include <cstring>
#include <vector>
#include <math.h>
#include <set>
#include <map>
#define ll long long
#define f(i,a,b) for(ll i=a;i<b;i++)
#define mod (1000*1000*1000+7)
#define vi vector < int >
#define vl vector < ll >

using namespace std;

int main(){
	int n;
	cin >> n;

	while(n--){
		int s;
		cin >> s;

		map <string,int> umap;

		cin.ignore();

		for(int i=0;i<s;i++){
			string s1;
			getline(cin,s1);
			umap[s1] = 0;
		}

		map <string,int> :: iterator it;

		string s2;

		int q;
		cin >> q;
		cout << q << endl;

		int count = 0;

		f(i,0,q){
			string s3;
			cin >> s3;

			cout << s3 << endl;


			if(s2 == "")
				s2 = s3;
			else if(s2 == s3)
				;
			else {
				umap[s3]++;
				s2 = s3;
			}
		}

		for(it=umap.begin();it!=umap.end();it++)
			cout << it->first << " --> " << it->second << endl;
	}
}