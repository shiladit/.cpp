// Input : arr[] = {2, 1, 4, 9, 2, 3, 8, 3, 4} 
//         k = 4
// Output : 5
// {2, 1, 4} => Length = 3
// {3, 4} => Length = 2
// So, 3 + 2 = 5 is the answer

#include <bits/stdc++.h>

using namespace std;

int main() {

	int arr[7] = {1, 2, 3, 2, 3, 4, 1} ;

	int k =4;

	int count = 0;
	int sum = 0;
	bool flag = false;

	for(int i=0;i<7;i++){
		if(arr[i] < k)
			count++;
		else if(arr[i] == k){
			count++;
			flag = true;
		}
		else{
			if(flag == true)
				sum += count;
			count = 0;
			flag = false;
		}
	}

	if(flag == true)
		sum += count;

	cout << sum << endl;
}