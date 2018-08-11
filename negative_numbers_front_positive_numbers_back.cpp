#include <bits/stdc++.h>

using namespace std;

vector <int> n_n_f_p_n_b(vector <int> arr){

int i=0;
int j= arr.size()-1;

while(i<j){
	if(arr[i]>=0 && arr[j]>=0)
		j--;
	else if(arr[i]>=0 && arr[j]<0){
		int temp= arr[i];
		arr[i] = arr[j];
		arr[j] = temp;

		j--;
		i++;
	}
	else if (arr[i]<0 && arr[j]<0){
		i++;
		
	}

	else {
		i++;
		j--;
	}

}
return arr;

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

	for(int i=0;i<size;i++) {
		cin >> temp;
		arr.push_back(temp);
	}

	vector <int> brr = n_n_f_p_n_b(arr);
	print_vector(brr);

}