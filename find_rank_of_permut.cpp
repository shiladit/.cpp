#include <bits/stdc++.h>
using namespace std;

long find_lower(string s,int low,int high){
	long count =0;

	for(int i=low+1;i<high;i++)
		if(s[low]>s[i])
			count++;

	return count;
}

long fact(long n){

	if(n == 1 || n == 0)
		return 1;

	return n*fact(n-1);
}


int main() {
	string s = "string";
	long rank = 1;

	for(int i=0;i<s.length();i++){
		long low_count = find_lower(s,i,s.length());

		rank = rank + ((low_count) * fact((s.length()-1)-i));
	}

	cout << rank << endl;
}