#include<bits/stdc++.h>

using namespace std;
#define DIM 100

int arr[DIM][DIM];

void print_matrix(int lower,int upper){
	// cout << lower << "--" << upper << endl;
	if(lower <=upper){
		for(int i=lower;i<upper;i++)
			cout << arr[lower][i] << " "; //printing first row
		for(int j= lower+1;j<upper-1;j++)
			cout << arr[j][upper-1] << " ";
		for(int k= upper-1;k>lower-1;k--)
			cout << arr[upper-1][k] << " ";
		for(int l= upper-2;l>lower;l--)
			cout << arr[l][lower] << " ";

		print_matrix(lower+1,upper-1);

	}
}

int main(){
	int size;
	cin >> size;
	int k=0;

	for(int i=0;i<size;i++)
		for(int j=0;j<size;j++){
			arr[i][j] = ++k;;
		}

	cout << "\nSpiral Ordering\n";	

	print_matrix(0,size);
	cout << endl;

}
