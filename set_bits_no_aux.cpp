#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin >> n;
	bool flag= true;
	int count =0;
	int num = n;
	int j=0;
	int temp;
	while(n != 0){

		temp = n%2;
		if(temp == 1)
			count++;

		
		n = n >> 1;
		j++;
	}

	// cout << j << endl;

	num = 3;
	int temp1 =pow(2,0);
	cout << temp1 << endl;
	int temp2 = pow(2,1);
	cout << temp2 << endl;
	if((num & temp1) == (num & temp2))
		cout << "hi\n";



	// for(int i=0;i<j/2;i++)
	// 	if((num & 2^i) != (num & 2^(j-i-1)))
	// 		flag= false;  

	// if(flag == true)
	// 	cout << "pal\n";
	// else
	// 	cout << "-1\n";
}