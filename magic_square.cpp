#include<bits/stdc++.h>

using namespace std;

int main() {
	int arr[9];
	int count_val =0;
	int min = 10000;
	int original_matrix[9];
	int temp;
	//INPUT
	for(int i=0;i<9;i++){
		cin >> temp;
		original_matrix[i] = temp ;
		// cout << original_matrix[i] << original_matrix[i+1] << original_matrix[i+2];
	}
	// cout << endl;

	
	for(int i=1;i<10;i++)
		for(int j=1;j<10;j++)
				for(int k=1;k<10;k++)
					for(int l=1;l<10;l++)
						for(int m=1;m<10;m++)
							for(int n=1;n<10;n++)
								for(int o=1;o<10;o++)
									for(int p=1;p<10;p++)
										for(int q=1;q<10;q++){
												arr[0]=i;
												arr[1]=j;
												arr[2]=k;
												arr[3]=l;
												arr[4]=m;
												arr[5]=n;
												arr[6]=o;
												arr[7]=p;
												arr[8]=q;
												//cout << arr[0] << arr[1] << arr[2] << arr[3] << arr[4] << arr[5] << arr[6] << arr[7] << arr[8]<< endl;
												
												//CHECKING MAGIC PROPERTIES

												int col1 = (arr[0]+arr[3]+arr[6]);
												int col2 = (arr[1]+arr[4]+arr[7]);
												int col3 = (arr[2]+arr[5]+arr[8]) ;
												int row1 = (arr[0]+arr[1]+arr[2]);
												int row2 = (arr[3]+arr[4]+arr[5]);
												int row3 = (arr[6]+arr[7]+arr[8]);
												int left_diag = (arr[0]+arr[4]+arr[8]);
												int right_diag = (arr[2]+arr[4]+arr[6]);

												if((row1 == row2) && (row1 == row3) && (col1 == col2) && (col1 == col3) && (row1==left_diag) && (row1 == right_diag)  &&
												(arr[0] != arr[1]) && (arr[0] != arr[2]) && (arr[0] != arr[3]) && (arr[0] != arr[4]) && (arr[0] != arr[5]) && (arr[0] != arr[6]) && (arr[0] != arr[7]) && (arr[0] != arr[8]) &&
												(arr[1] != arr[2]) && (arr[1] != arr[3]) && (arr[1] != arr[4]) && (arr[1] != arr[5]) && (arr[1] != arr[6]) && (arr[1] != arr[7]) &&
												(arr[1] != arr[8]) && (arr[2] != arr[3]) && (arr[2] != arr[4]) && (arr[2] != arr[5]) && (arr[2] != arr[6]) && (arr[2] != arr[7]) && (arr[2] != arr[8]) &&
												(arr[3] != arr[4]) && (arr[3] != arr[5]) && (arr[3] != arr[6]) && (arr[3] != arr[7]) && (arr[3] != arr[8]) &&
												(arr[4] != arr[5]) && (arr[4] != arr[6]) && (arr[4] != arr[7]) && (arr[4] != arr[8]) && 
												(arr[5] != arr[6]) && (arr[5] != arr[7]) && (arr[5] != arr[8]) &&
												(arr[6] != arr[7]) && (arr[6] != arr[8]) &&
												(arr[7] != arr[8])) {
															//I AM GETTING THE MAGIC SQUARES HERE 
															// cout << arr[0] << arr[1] << arr[2] << arr[3] << arr[4] << arr[5] << arr[6] << arr[7] << arr[8]<< endl;	

															int diff = 0 ;
															for(int i=0 ;i<9;i++){
																// cout << arr[i] << "--" << original_matrix[i] << endl;
																diff += abs(arr[i]-original_matrix[i]); 
															}
															
															// cout << diff <<endl;
															

															if(diff < min)
																min = diff;
												
															}
													
										} //END FOR
										cout << min << endl;
	
  
}