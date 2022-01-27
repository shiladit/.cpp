#include <bits/stdc++.h>
using namespace std;


int main() {

	int size,temp;
	cin >> size;

	vector <vector <int> > arr(size,vector <int> (size));

	for(int i=0;i<arr.size();i++)
		for(int j=0;j<arr[i].size();j++){
			cin >> temp;
			arr[i][j] = temp;
		}

	vector <vector <int> > aux(size,vector <int> (size));

	for(int i=0;i<arr[0].size();i++)
		aux[0][i] = arr[0][i];

	for(int i=0;i<arr.size();i++)
		aux[i][0] = arr[i][0];

	for(int i=1;i<aux.size();i++)
		for(int j=1;j<aux[i].size();j++){
			if(arr[i][j] == 0)
				aux[i][j] = 0;
			else if(arr[i][j] == 1 && aux[i-1][j] != 0 && aux[i-1][j-1] !=0 && aux[i][j-1] != 0)
				aux[i][j] = 1 + min(aux[i-1][j-1],min(aux[i-1][j],aux[i][j-1]));
			else
				aux[i][j] = 1;
		}
	

	for(int i=0;i<aux.size();i++){
		for(int j=0;j<aux[i].size();j++){
			cout << aux[i][j] << " ";
			}	
			cout << endl;
	}
}