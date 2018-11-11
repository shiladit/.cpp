#include <bits/stdc++.h>
using namespace std;

int main() {
	int arr[4][5] = {{1,2,-1,-4,-20},{-8,-3,4,2,1},{3,8,10,1,3},{-4,-1,1,7,-6}};


	long max_sum = -9999;

	for(int start=0;start<=4;start++)
		for(int end=start+1;end<=5;end++){
			long sum = 0;
			for(int i=start;i<end;i++){
				for(int j=start;j<end;j++){
					sum = sum + arr[i][j]; 
				}
			}
			if(sum > max_sum)
				max_sum = sum;
		}


	cout << max_sum << endl;

}