#include<bits/stdc++.h>

using namespace std;

int min(int x,int y,int z){
	return min(x,min(y,z));
}

int edit_distance(string s1,string s2, int m, int n){

	int aux[m+1][n+1];

	for(int i=0;i<m+1;i++)
		for(int j=0;j<n+1;j++){
			if(i==0)
				aux[i][j] = j;

			else if(j==0)
				aux[i][j] =i ;

			else if(s1[i-1] == s2[j-1])
				aux[i][j] = aux[i-1][j-1];

			else
				aux[i][j] = 1 + min(aux[i-1][j],aux[i][j-1],aux[i-1][j-1]);

		}


		for(int i=0;i<m+1;i++){
			for(int j=0;j<n+1;j++){
				cout << aux[i][j] << " ";
			}
			cout << endl;
		}


		return aux[m][n];
}


int main(){
	string s1,s2;
	cin >> s1 >> s2;

	cout << edit_distance(s1,s2,s1.length(),s2.length());
}