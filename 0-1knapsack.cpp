#include <iostream>

using namespace std;

void knapSack (int W,int wt[],int val[],int n) {

	int arr[W+1][W+1];


    //DP 
	for(int i=0;i<=W;i++)
		for(int j=0;j<=W;j++) {
             //cout << "i: "<< i << "j: " << j << endl;

			    if(i ==0 || j==0)
			    	arr[i][j] = 0;
				else if (wt[i-1]<=j)			    
					arr[i][j] = max (arr[i-1][j] ,val[i-1] + arr[i-1][j-wt[i-1]]);
				else
					arr[i][j] = arr[i-1][j];

}

	cout <<  arr[n][W] << endl ;		


}


int main()
{
    int val[] = {1,4,5,7};
    int wt[] = {1,3,4,5};
    int  W = 7;
    int n = sizeof(val)/sizeof(val[0]);
    knapSack(W, wt, val, n);
    return 0;
}