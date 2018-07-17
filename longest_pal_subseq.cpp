#include<bits/stdc++.h>

using namespace std;


int LPS(char seq[],int n) {

	int arr[n][n];

	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			if(i==j)
				arr[i][j]=1;
			else 
				arr[i][j] = -1;

	

	int l=2;
	
	while(l<=n){
		for(int i=0;i+l-1<=n;i++)
			{
			int j=i+l-1;	
			if(seq[i]!=seq[j])
			arr[i][j] = max(arr[i][j-1],arr[i+1][j]);
			else
			arr[i][j] = 2 + arr[i+1][j-1];
			}
			l++;
	}

	return arr[0][n-1];



	// for(int i=0;i<n;i++) {
	// 	for(int j=0;j<n;j++) {
	// 		cout << arr[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }
}


int main()
{
    char seq[] = "agbdba";
    int n = strlen(seq);
    
    cout << LPS(seq,n) << endl;
    
    return 0;
}