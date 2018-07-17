#include <bits/stdc++.h>

using namespace std;


void lcs(char X[],char Y[],int m,int n) {
	int arr[m+1][n+1];

	for(int i=0;i<=m;i++)
		for(int j=0;j<=n;j++) {
			if(i ==0 || j==0)
				arr[i][j]=0;
			else if (X[i-1] == Y[j-1])
				arr[i][j] = 1+ arr[i-1][j-1];
			else
				arr[i][j] = max(arr[i-1][j] , arr[i][j-1]);
			}


    // for(int i=0;i<=m;i++) {
    // 	for(int j=0;j<=n;j++) {
    // 		cout << arr[i][j] << " " ; 
    // 	}
    // 	cout << endl ;
    // }

	 cout << "The length of lcs is: " arr[m][n] << endl;
}


int main()
{
  char Y[] = "AGGTAB";
  char X[] = "GXTXAYB";
 
  int m = strlen(X);
  int n = strlen(Y);
 
 lcs( X, Y, m, n );
 
  return 0;
}