#include<bits/stdc++.h>

using namespace std;

void CoinChange(int coins[],int n,int sum){
	int arr[sum+1];

	//INIT
	for (int i=1;i<sum+1;i++)
		arr[i] = 99999;

	arr[0]= 0;
   
 //   //PRINT
	// for (int i=0;i<sum+1;i++)
	// 	cout << arr[i] << " " << endl;


	for(int i=0;i<n;i++)
		for(int j=1;j<sum+1;j++){
			if(j<coins[i])
				arr[j] = 9999;
			else 
				arr[j] = min(arr[j] , 1+arr[j-coins[i]]);
		}
    //PRINT
	// for (int i=0;i<sum+1;i++)
	// 	cout << arr[i] << " " ;

	cout << arr[sum] << endl;
}


int main()
{
    int coins[] = {7, 2, 3,6};
    int n = sizeof(coins)/sizeof(coins[0]);

    int sum = 13; 
    CoinChange(coins,n,sum);
    return 0;
}