#include<bits/stdc++.h>

using namespace std;


/* In this case XOR is associative, so the sequence of Xor-ing doesn't matter. If the number of elements are even, then
the XOR-ing would give 0, since it creates a perfect symmetry when expanded out. However if the numbers are odd, then we
need to XOR only elements in the even places. Try expanding it out with an example to see */

int main() {


	int size,T;
	long temp;

	cin >> T;

	while(T) {
	
	cin >> size;
	vector <long> arr;

	for(int i=0;i<size;i++){
		cin >> temp;
		arr.push_back(temp);
	}
	
	if(size%2 == 0)
		cout << "0" << endl;
	else
		{	
			long val = arr[0];
			for(int i=2;i<size;i=i+2)
				val = val^arr[i];

			cout << val << endl;
		}




	T--;
	}
}