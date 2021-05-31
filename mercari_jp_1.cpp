//shiladitya
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <math.h>
#include <iomanip>
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

vector <int> arr;

long conv(string s){

	int num = 0;

	int len = s.length();
	int j = 0;

	for(int i = len-1;i>=0;i--){
		if(s[j++] == '1')
			num = num + pow(2,i);
	}

	return num;
}

void conv_to_b(int a){

	while(a){
		if(a & 1)
			arr.push_back(1);
		else
			arr.push_back(0);
		a = a >> 1;
	}
}

int main() {

	string s1,s2;
	cin >> s1 >> s2;

	long num1 =  conv(s1);
	long num2 =  conv(s2);

	num1 = num1+num2;

	conv_to_b(num1);

	for(int i=arr.size()-1;i>=0;i--)
		cout << arr[i] << " " ;

	cout << endl;

}