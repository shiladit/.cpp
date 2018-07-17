#include<bits/stdc++.h>

using namespace std;

int min(int x,int y,int z) {
	return min(min(x,y),z);
}


void editDist(string str1,string str2, int m,int n) {

	int arr[m+1][n+1];

for(int i=0;i<m+1;i++)
	arr[i][0]=i;

for(int j=0;j<n+1;j++)
	arr[0][j]=j;
	
	//PRINT
for(int i=0;i<m+1;i++){
	for(int j=0;j<n+1;j++) {
		cout << arr[i][j] << "  " ;
	}
	cout << endl;
}

for(int i=1;i<m+1;i++){
	for(int j=1;j<n+1;j++) {
		if(str1[i-1] == str2[j-1])
			arr[i][j] = 0 + arr[i-1][j-1];
		else 
			arr[i][j] = 1 + min(arr[i-1][j],
								arr[i][j-1],
								arr[i-1][j-1]);
		}
	
	}

cout << "----------------------------------" << endl;

for(int i=0;i<m+1;i++){
	for(int j=0;j<n+1;j++) {
		cout << arr[i][j] << "  " ;
	}
	cout << endl;
}


}


int main() {

    string str1 = "sunday";
    string str2 = "saturday";
 
	editDist( str1 , str2 , str1.length(), str2.length());
 
    return 0;

}