#include<bits/stdc++.h>

using namespace std;


int main(){

	int ele[] = {3,4,-1,0,6,2,3};
	int n = 7;

	int arr[n];

	//INIT
	for(int i=0;i<n;i++)
		arr[i]=1;

	for(int i=1;i<n;i++)
		for(int j=0;j<i;j++)
			if(ele[i]>ele[j])
				arr[i] = max(arr[i],arr[j]+1);

	//PRINT
	for(int i=0;i<n;i++)
		cout <<  arr[i] << "  ";

	cout << endl;


}