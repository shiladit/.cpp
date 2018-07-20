#include<bits/stdc++.h>

using namespace std;

int arr[1000][1000];
int copy_matrix[1000][1000];

void rotting(int i,int j,int r,int c) {

	//UP
	if(arr[i-1][j] == 1 && (i>0))
		arr[i-1][j] = 2;

	//DOWN
	if(arr[i+1][j] == 1 && (i<r-1))
		arr[i+1][j] = 2;

	//RIGHT
	if(arr[i][j+1] == 1 && (j<c-1))
		arr[i][j+1] = 2;

	//LEFT
	if(arr[i][j-1] == 1 && (j>0))
		arr[i][j-1] = 2;

}

void print (int r ,int c) {

	cout << "----PRINTING----" << endl;

	for(int i=0;i<r;i++) {
		for(int j=0;j<c;j++){
			cout << arr[i][j] << " " ; 
		}
		cout << endl;
	}
}

void call_rot_func(int r,int c) {
	int time =0;
	bool same = false;

	while(same == false) {
	//COPY ELEMENTS

	for(int i=0;i<r;i++)
		for(int j=0;j<c;j++) 
			copy_matrix[i][j]= arr[i][j];

	

	for(int i=0;i<r;i++)
		for(int j=0;j<c;j++) {
			if(arr[i][j] == 2)
				rotting(i,j,r,c);
		}
	cout << endl;
	print(r,c);

	same = true;
	//Checking if values in both matrices are same	
	for(int i=0;i<r;i++)
		for(int j=0;j<c;j++) {
			if(copy_matrix[i][j] != arr[i][j])
			    same = false; 
		}

	time++;


	}

	for(int i=0;i<r;i++)
		for(int j=0;j<c;j++) {
			if(arr[i][j] == 1){
				cout << "\nNot Fine\n";
				cout << "\n-1\n" ;
				return ; 
			}
		}

	cout << "\nAll Fine\n";

	cout << endl << time << endl;


}

int main() {
	int T,r,c;
	cin >> T;
	while(T) {
		cin >> r >> c;


		for(int i=0;i<r;i++)
			for(int j=0;j<c;j++){
				cin >> arr[i][j];
			}

		call_rot_func(r,c);	


		T--;
	}
}