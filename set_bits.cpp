#include<bits/stdc++.h>

using namespace std;

bool check_pali (vector <int> binary) {
	int i,j;
	for(i=0,j=binary.size()-1;i<=j;i++,j--){
		if(binary[i] != binary[j])
			return false;
	}


	return true;

}


int main() {

	long num;

	cin >> num ;
	vector <int> binary;
	int temp;
	int count =0 ;

	while(num != 0){

		temp = num%2;
		if(temp == 1)
			count++;

		binary.push_back(temp);
		num = num >> 1;


	}

	bool flag =check_pali(binary);

	if(flag == true)
		cout << count << endl;
	else
		cout << "-1" << endl;
}