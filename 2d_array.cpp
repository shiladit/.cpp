#include<iostream>
using namespace std;

int arr[6][6]; // global fixed size array
int arrx[7] = {0,-1,-1,-1,1,1,1};
int arry[7] = {0,-1,0,1,-1,0,1};

int hourglass_sum(int a,int b)
{
	int sum = 0;
	for(int i=0;i<7;i++)
	{
		sum += arr[a+arrx[i]][b+arry[i]];
	}
	
	return sum;
}

int main()
{
	int temp;
	/* input */
	for(int i=0;i<6;i++)
	{
		for(int j=0;j<6;j++)
		{
			cin >> temp;
			arr[i][j] = temp;
		}
	}
	
	int sum = -100000;

	for(int i=1;i<5;i++)
		for(int j=1;j<5;j++)
		{
			int val = hourglass_sum(i,j);
			if(val > sum)
				sum = val;
		}

	cout << sum << endl;
	return 0;
}
