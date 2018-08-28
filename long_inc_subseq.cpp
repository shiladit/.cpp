#include<bits/stdc++.h>

using namespace std;

int main() {
	int size,temp;
	cin >> size;

	vector <int> arr;

	for(int i=0;i<size;i++){
		cin >> temp;
		arr.push_back(temp);
	}

	//Create aux array

	vector <int> aux(size,1);

	for(int i=1;i<arr.size();i++)
		for(int j=0;j<i;j++){
			if(arr[j]<arr[i])
				aux[i] = max(aux[i],aux[j]+1);
		}

	cout << aux[size-1] << endl;	
}
