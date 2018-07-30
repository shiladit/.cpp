#include<bits/stdc++.h>

using namespace std;

int main() {
	long N;
	long temp;

	cin >> N;

	vector <long> arr;
	vector <long> right_greater(N,0);
	vector <long> left_greater(N,0);
	
	for(int i=0;i<N;i++){
        cin >> temp;
        arr.push_back(temp);
    }

	stack <long> s1;
	
	//FINDING RIGHT GREATEST
	for(int i=0;i<N;i++){

		while(!s1.empty() && arr[s1.top()-1]<arr[i]){
			int r = s1.top();
			s1.pop();
			right_greater[r-1] = i+1;

		}
		

		// for(int i=0;i<N;i++)
		// 	cout << right_greater[i] << " ";

		// cout << "\n------------------\n";

		s1.push(i+1);
		
	}



	//FINDING LEFT GREATEST

	stack <long> s2;
	
	//FINDING RIGHT GREATEST
	for(int i=N-1;i>=0;i--){

		while(!s1.empty() && arr[s1.top()-1]<arr[i]){
			int r = s1.top();
			s1.pop();
			left_greater[r-1] = i+1;

		}
		

		// for(int i=0;i<N;i++)
		// 	cout << left_greater[i] << " ";

		// cout << "\n------------------\n";

		s1.push(i+1);
		
	}

	long max_val = -INT_MAX;

	for(int i=0;i<N;i++){
		long prod = left_greater[i]*right_greater[i];
		if(prod > max_val)
			max_val = prod;


	}

	cout << max_val << endl;

}