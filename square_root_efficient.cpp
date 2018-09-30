#include <bits/stdc++.h>

using namespace std;

int find_square(int num,int low,int high){

if(low<high){
	int mid = (low+high)/2;

	if((mid*mid) == num){
		return mid;
		
	}
	else if((mid*mid) < num)
		return find_square(num,mid+1,high);
	else
		return find_square(num,low,mid);
	}
	return -1;

}

int main() {
	int x;
	cin >> x;

	if(x == 1)
		cout << 1 << endl;
	else
		cout << find_square(x,0,x) << endl;
}