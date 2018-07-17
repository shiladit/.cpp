#include <bits/stdc++.h>

using namespace std;


void isSubsetSum(int set[],int n,int sum){
	bool arr[n+1][sum+1];

    //INIT
	for(int i=0;i<n+1;i++)
		for(int j=0;j<sum+1;j++) {
			if(i==0)
				arr[i][j] = false;
			
			else if (j==0)
				arr[i][j] = true;
		}

	arr[0][0] = true;


    //DP
	for(int i=1;i<n+1;i++)
		for(int j=1;j<sum+1;j++) {
			if (j<set[i-1])
				arr[i][j] = arr[i-1][j];

			else if( j==set[i-1])
				 arr[i][j] = true;
			
			else if (!arr[i-1][j])
				arr[i][j] = true && arr[i-1][j-set[i-1]];
			else 
				arr[i][j] = true ;
     }

	for(int i=1;i<n+1;i++) {
		for(int j=1;j<sum+1;j++) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}	


 }
    

int main()
{
  int set[] = {2, 3, 7, 8, 10};
  int sum = 11;
  int n = sizeof(set)/sizeof(set[0]);
  isSubsetSum(set, n, sum);
  return 0;
}