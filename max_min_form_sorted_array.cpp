#include<bits/stdc++.h>

using namespace std;

vector <int> find_max_min(vector <int> arr){
	vector <int> aux;

	int i=0;
	int j=arr.size()-1;

	while(i<j){
		if(arr[i]<arr[j]){
			aux.push_back(arr[j]);
			aux.push_back(arr[i]);
			j--;
			i++;
		}
	}

	//ODD NUMBER OF ELEMENTS CASE
	if(arr.size()%2 != 0)
		aux.push_back(arr[(arr.size()/2)]);

	return aux; 
}

void print_vector(vector <int> brr){
	for(int i=0;i<brr.size();i++)
		cout << brr[i] << " ";

	cout << endl;
}


int main() {
	int size,temp;
	cin >> size;

	vector <int> arr;

	for(int i=0;i<size;i++){
		cin >> temp;
		arr.push_back(temp);
	}

	vector <int> brr = find_max_min(arr);

	print_vector(brr);
}