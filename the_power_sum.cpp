#include <bits/stdc++.h>
using namespace std;

int count_ways(int num,int val,int N){

	if(num < 0)
		return 0;
	if(num == 0)
		return 1;
	if(val > num)
		return 0;
	 
    return count_ways(num-pow(val,N),val+1,N) + count_ways(num,val+1,N);
}


int main() {
	int num, N;
	cin >> num;
	cin >> N;

	cout << count_ways(num,1,N) << endl;
}