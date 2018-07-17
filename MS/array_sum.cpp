#include<bits/stdc++.h>

using namespace std;


int main() {

	int T; //test cases
	cin >> T;

	int size, sum;

	while(T) {
		cin >> size >> sum;

		int arr[size]; 

		for(int i=0;i<size;i++) {
			int ele;
			cin >> ele;
			arr[i]=ele;
			// cout << arr[i] << " ";
		}

		bool flag=false;

		//BRUTE FORCE
		// for(int i=0;i<size;i++)
		// 	for(int j=0;j<size;j++)
		// 		if(i!=j && (arr[i] + arr[j] == sum))
		// 			flag = true;

		sort(arr,arr+size);
		int i=0;
		int j=size-1;

		while(i!=j){
			if(arr[i] + arr[j] == sum){
				flag =true;
				break;
			}
			else if(arr[i] + arr[j] > sum)
				j--;
			else 
				i++;
		}




		if(flag)
			cout << "Present\n" ;
		else
			cout << "Not Present\n";



		T--;

	}



}