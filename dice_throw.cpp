/* Minimum number of moves required for n different dice with m different pips to all show the same face */

//shiladitya
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <climits>

using namespace std;

int main(){
	int n;
	cin >> n;

	vector <int> arr;

	for(int i=0;i<n;i++){
		int x;
		cin >> x; arr.push_back(x);
	}

	/* Brute force */
	/* Two face of a die will always add upto 7 */
	int min_val = INT_MAX;
	

	for(int j=1;j<=6;j++){
		int count = 0;
		for(int i=0;i<n;i++){

			if(arr[i] == j)
				count +=0;
			else if (arr[i] == (7-j))
				count += 2;
			else
				count += 1;

		}
		if(count < min_val)
			min_val = count;
	}

	cout << min_val << endl;
}